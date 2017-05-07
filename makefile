
all: dfs generator generator2

dfs: dfs.cpp
	g++ -std=c++11 dfs.cpp -o dfs

generator: generator.cpp
	g++ generator.cpp -o generator

generator2: generator2.cpp
	g++ generator2.cpp -o generator2

clean:
	rm -f *.o dfs generator generator2

