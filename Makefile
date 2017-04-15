all: bin
bin: tilemesh.cpp tilemesh.h
	g++ -I. -I vendor/o5mdecoder tilemesh.cpp -o tilemesh --debug
