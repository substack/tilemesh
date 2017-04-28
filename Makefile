all: bin
bin: tilemesh.cpp tilemesh.h
	g++ -std=c++11 -I. -I vendor tilemesh.cpp -o tilemesh --debug
