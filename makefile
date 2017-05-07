
all: dfs

dfs: dfs.cpp
	g++ -std=c++11 dfs.cpp -o dfs

generator: generator.cpp
	g++ generator.cpp -o generator
	./generator input2.txt

generator2: generator2.cpp
	g++ generator2.cpp -o generator2
	./generator2 input3.txt

test: dfs
	./dfs input.txt

test2: dfs
	./dfs input2.txt

test3: dfs
	./dfs input3.txt

clean:
	rm -f *.o dfs generator generator2

