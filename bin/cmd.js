#!/usr/bin/env node
var minimist = require('minimist')
var tilegen = require('../generate.js')
var argv = minimist(process.argv.slice(2))

process.stdin.pipe(tilegen(function (err, mesh) {
  if (err) error(err)
  else console.log(JSON.stringify(mesh))
}))

function error (err) {
  console.error(err)
  process.exit(1)
}
