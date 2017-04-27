
all: dfs

dfs: dfs.cpp
	g++ -g -std=c++11 -g dfs.cpp -o dfs

test: dfs
	./dfs input.txt

clean:
	rm -f *.o dfs

