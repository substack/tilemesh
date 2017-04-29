/*
Copyright (c) 2017 James Halliday

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef O5MDECODER_H
#define O5MDECODER_H

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

namespace o5mdecoder {
  typedef unsigned char TYPE;
  const TYPE NODE = 0x10;
  const TYPE WAY = 0x11;
  const TYPE REL = 0x12;
  const uint32_t MAX_TABLE_SIZE = 15000;
  enum _STATE {
    _BEGIN = 1,
    _TYPE = 2,
    _LEN = 3,
    _DATA = 4,
    _END = 5
  };
  size_t signedDelta (int64_t *d, size_t len, char *data) {
    size_t i;
    unsigned char b, m = 0x40;
    int64_t npow = data[0]%2 ? -1 : 1;
    for (i = 0; i < len; i++) {
      b = data[i] >> (i == 0 ? 1 : 0);
      *d += (b % m) * npow;
      if (b < 0x80) break;
      npow *= m;
      m = 0x80;
    }
    if (npow < 0) *d -= 1;
    return i+1;
  }
  size_t signedDelta (uint64_t *d, size_t len, char *data) {
    return signedDelta((int64_t*)d, len, data);
  }
  size_t xunsigned (uint64_t *d, size_t len, char *data) {
    size_t i;
    unsigned char b;
    int64_t npow = 1;
    for (i = 0; i < len; i++) {
      b = data[i];
      *d += (b & 0x7f) * npow;
      if (b < 0x80) break;
      npow *= 0x80;
    }
    return i+1;
  }
  size_t xunsigned (int64_t *d, size_t len, char *data) {
    return xunsigned((uint64_t*)d, len, data);
  }
  struct Member {
    TYPE type;
    uint64_t ref;
    char *role;
  };
  class Doc {
    public:
    TYPE type;
    uint64_t id;
    uint64_t version;
    int64_t timestamp;
    uint64_t changeset;
    uint64_t uid;
    size_t _taglen,_tagpos;
    char *user, *_err, *_tags, *_table;
    size_t *_tablesize, *_tablepos;
    Doc () {
      id = 0;
      version = 0;
      timestamp = 0;
      changeset = 0;
      uid = 0;
      user = NULL;
      _table = NULL;
      _tablesize = NULL;
      _tablepos = NULL;
    }
    bool getTag (char **key, char **value) {
      size_t begin, end;
      uint64_t ntable;
      if (_tagpos >= _taglen) return false;
      if (*(_tags+_tagpos) == 0) {
        begin = ++_tagpos;
        *key = _tags+_tagpos;
        for (_tagpos++;*(_tags+_tagpos) != 0 && _tagpos < _taglen; _tagpos++);
        _tagpos++;
        *value = _tags+_tagpos;
        for (;*(_tags+_tagpos) != 0 && _tagpos < _taglen; _tagpos++);
        end = ++_tagpos;
        memcpy(_table+256*(*_tablepos), _tags+begin, end-begin);
        *_tablepos = ((*_tablepos)+1)%MAX_TABLE_SIZE;
        *_tablesize = fminl((*_tablesize)+1, MAX_TABLE_SIZE);
        return true;
      } else {
        ntable = 0;
        _tagpos += xunsigned(&ntable, _taglen-_tagpos, _tags+_tagpos);
        if (ntable > *_tablesize) {
          sprintf(_err, "table number greater than table size: %u > %u",
            ntable, *_tablesize);
          throw _err;
        }
        *key = _table+256*((*_tablepos)-ntable);
        for (begin = 0; begin < 256 && *(*key+begin) != 0; begin++);
        *value = begin+*key+1;
        return true;
      }
      return false;
    }
  };
  class Node : public Doc {
    public:
    double lat;
    double lon;
    int64_t ulat;
    int64_t ulon;
    Node () {
      lon = 0;
      lat = 0;
      ulon = 0;
      ulat = 0;
    }
  };
  class Way : public Doc {
    public:
    size_t _reflen, _refpos;
    uint64_t _ref;
    char *_refbuf;
    Way () {
      _ref = 0;
    }
    bool getRef (uint64_t *ref) {
      if (_refpos >= _reflen) return false;
      _refpos += signedDelta(&_ref, _reflen-_refpos, _refbuf+_refpos);
      *ref = _ref;
      return true;
    }
  };
  class Rel : public Doc {
    public:
    size_t _memlen, _mempos;
    uint64_t _ref;
    char *_membuf;
    bool getMember (Member *member) {
      uint64_t ntable;
      size_t begin;
      if (_mempos >= _memlen) return false;
      _mempos += signedDelta(&_ref, _memlen-_mempos, _membuf+_mempos);
      member->ref = _ref;
      if (*(_membuf+_mempos) == 0) {
        _mempos++;
        begin = _mempos;
        member->type = ((unsigned char) *(_membuf+_mempos)) - 0x20;
        _mempos++;
        member->role = _membuf+_mempos;
        for (; _mempos < _memlen && *(_membuf+_mempos) != 0; _mempos++);
        _mempos++;
        memcpy(_table+(*_tablepos)*256,_membuf+begin,_mempos-begin);
        *_tablesize = fminl((*_tablesize)+1,MAX_TABLE_SIZE);
        *_tablepos = ((*_tablepos)+1)%MAX_TABLE_SIZE;
      } else {
        ntable = 0;
        _mempos += xunsigned(&ntable, _memlen-_mempos, _membuf+_mempos);
        if (ntable > *_tablesize) {
          sprintf(_err, "table number greater than table size: %u > %u",
            ntable, *_tablesize);
          throw _err;
        }
        begin = 256*((*_tablepos)-ntable);
        member->type = (unsigned char) *(_table+begin) - 0x20;
        member->role = _table+begin+1;
      }
      return true;
    }
  };
  class Decoder {
    public:
    char *buffer, *docbuf, *table, *_key, *_value;
    size_t length, docbuflen, pos, tablesize, tablepos, _ref;
    size_t doclen, docpow, docsize;
    char _err[256];
    Member _member;
    Node *node;
    Node _node;
    Way *way;
    Way _way;
    Rel *rel;
    Rel _rel;
    Node *_prevNode;
    Way *_prevWay;
    Rel *_prevRel;
    Doc *_prevDoc;
    TYPE type;

    _STATE _state;
    Decoder (char *dbuf, size_t buflen, char *stable) {
      _state = _BEGIN;
      table = stable;
      tablesize = 0;
      tablepos = 0;
      buffer = NULL;
      pos = 0;
      docbuf = dbuf;
      docbuflen = buflen;
      length = 0;
      docpow = 1;
      doclen = 0;
      docsize = 0;
      node = NULL;
      way = NULL;
      rel = NULL;
      _prevDoc = NULL;
      _prevNode = NULL;
      _prevWay = NULL;
      _prevRel = NULL;
      _node._table = table;
      _node._tablesize = &tablesize;
      _node._tablepos = &tablepos;
      _node._err = _err;
      _way._table = table;
      _way._tablesize = &tablesize;
      _way._tablepos = &tablepos;
      _way._err = _err;
      _rel._table = table;
      _rel._tablesize = &tablesize;
      _rel._tablepos = &tablepos;
      _rel._err = _err;
    }
    void write (char *data, size_t len) {
      buffer = data;
      length = len;
      pos = 0;
    }
    bool read () {
      node = NULL;
      way = NULL;
      rel = NULL;
      if (_prevDoc) while (_prevDoc->getTag(&_key,&_value));
      if (_prevWay) while (_prevWay->getRef(&_ref));
      if (_prevRel) while (_prevRel->getMember(&_member));

      size_t j;
      for (; pos < length; pos++) {
        unsigned char b = buffer[pos];
        if (_state == _BEGIN && b != 0xff) {
          sprintf(_err, "first byte in frame, expected 0xff, got 0x%x", b);
          throw _err;
        } else if (_state == _BEGIN) {
          _state = _TYPE;
        } else if (_state == _TYPE && b == 0xff) { // reset
          _state = _TYPE;
          _prevDoc = NULL;
          _prevNode = NULL;
          _prevWay = NULL;
          _prevRel = NULL;
        } else if (_state == _TYPE) {
          _state = _LEN;
          type = b;
        } else if (_state == _LEN) {
          doclen += (b & 0x7f) * docpow;
          docpow *= 0x80;
          if (b < 0x80) {
            _state = _DATA;
          }
        } else if (_state == _DATA) {
          j = fminl(length, pos + doclen - docsize);
          if (docsize+j-pos >= docbuflen) {
            sprintf(_err, "Buffer space exceeded. Try using a larger buffer.");
            throw _err;
          }
          memcpy(docbuf+docsize, buffer+pos, j-pos);
          docsize += j - pos;
          pos = j;
          if (docsize == doclen) {
            if (type == NODE) _parseNode(doclen, docbuf);
            else if (type == WAY) _parseWay(doclen, docbuf);
            else if (type == REL) _parseRel(doclen, docbuf);
            _state = _TYPE;
            doclen = 0;
            docpow = 1;
            docsize = 0;
            return true;
          }
        } else if (_state == _END) {
          // ...
        }
      }
      return false;
    }
    size_t _parseDoc (Doc *doc, size_t len, char *buf) {
      size_t pos = 0, begin = 0;
      int64_t ntable;
      if (_prevDoc) {
        doc->id = _prevDoc->id;
        doc->timestamp = _prevDoc->timestamp;
        doc->changeset = _prevDoc->changeset;
      } else {
        doc->id = 0;
        doc->version = 0;
        doc->timestamp = 0;
        doc->changeset = 0;
      }
      doc->version = 0;
      doc->uid = 0;
      doc->user = NULL;
      pos += signedDelta(&(doc->id), len-pos, buf+pos);
      if (buf[pos] == 0x00) { // no version
        doc->version = 0;
        doc->timestamp = 0;
        doc->changeset = 0;
        pos++;
      } else {
        pos += xunsigned(&(doc->version), len-pos, buf+pos);
        pos += signedDelta(&(doc->timestamp), len-pos, buf+pos);
        if (doc->timestamp == 0) {
          doc->changeset = 0;
        } else {
          pos += signedDelta(&(doc->changeset), len-pos, buf+pos);
          if (*(buf+pos) == 0) { // inline string
            begin = ++pos;
            pos += xunsigned(&(doc->uid), len-pos, buf+pos);
            if (*(buf+pos) != 0) {
              sprintf(_err, "expected 0x00 after uid, got 0x%x", *(buf+pos));
              throw _err;
            }
            for (; pos < len && *(buf+pos) != 0; pos++);
            pos++;
            doc->user = buf+pos;
            for (; pos < len && *(buf+pos) != 0; pos++);
            pos++;
            memcpy(table+tablepos*256,buf+begin,pos-begin);
            tablesize = fminl(tablesize+1,MAX_TABLE_SIZE);
            tablepos = (tablepos+1)%MAX_TABLE_SIZE;
          } else { // string table lookup
            ntable = 0;
            pos += xunsigned(&ntable, len-pos, buf+pos);
            if (ntable > tablesize) {
              sprintf(_err, "table number greater than table size: %u > %u",
                ntable, tablesize);
              throw _err;
            }
            begin = xunsigned(&(doc->uid), 256, table+256*(tablepos-ntable));
            doc->user = table+256*(tablepos-ntable)+begin+1;
          }
        }
      }
      return pos;
    }
    size_t _parseTags (Doc *doc, size_t len, char *buf) {
      doc->_tags = buf;
      doc->_taglen = len;
      doc->_tagpos = 0;
      return len;
    }
    void _parseNode (size_t len, char *buf) {
      node = &_node;
      size_t pos = _parseDoc(node, len, buf);
      int64_t ulat = _prevNode ? _prevNode->ulat : 0;
      int64_t ulon = _prevNode ? _prevNode->ulon : 0;
      pos += signedDelta(&ulon, len-pos, buf+pos); // lon
      pos += signedDelta(&ulat, len-pos, buf+pos); // lat
      node->ulon = ulon;
      node->ulat = ulat;
      node->lon = ((double) ulon) / 1e7;
      node->lat = ((double) ulat) / 1e7;
      pos += _parseTags(node, len-pos, buf+pos);
      _prevNode = node;
      _prevDoc = node;
    }
    void _parseWay (size_t len, char *buf) {
      way = &_way;
      size_t pos = _parseDoc(way, len, buf);
      way->_reflen = 0;
      way->_refpos = 0;
      way->_ref = _prevWay ? _prevWay->_ref : 0;
      pos += xunsigned(&(way->_reflen), len-pos, buf+pos);
      way->_refbuf = buf+pos;
      pos += way->_reflen;
      pos += _parseTags(way, len-pos, buf+pos);
      _prevWay = way;
      _prevDoc = way;
    }
    void _parseRel (size_t len, char *buf) {
      rel = &_rel;
      size_t pos = _parseDoc(rel, len, buf);
      rel->_memlen = 0;
      rel->_mempos = 0;
      rel->_ref = 0;
      pos += xunsigned(&(rel->_memlen), len-pos, buf+pos);
      rel->_membuf = buf+pos;
      pos += rel->_memlen;
      pos += _parseTags(rel, len-pos, buf+pos);
      _prevRel = rel;
      _prevDoc = rel;
    }
  };
}

#endif
