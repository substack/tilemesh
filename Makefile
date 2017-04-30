all: bin
bin: tilemesh.cpp src/tilemesh.hpp
	g++ -std=c++11 -I. -Isrc tilemesh.cpp -o tilemesh --debug -O3
