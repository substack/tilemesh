all: bin
bin: tilemesh.cpp tilemesh.hpp
	g++ -std=c++11 -I. tilemesh.cpp -o tilemesh --debug -O3
