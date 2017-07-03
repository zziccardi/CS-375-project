
# Depth-first search #

To compile the main DFS program (dfs.cpp), run `make dfs`.

To compile the first generator (generator.cpp, which generates regular graphs), run `make generator`.

To compile the second generator (generator2.cpp, which generates binary trees), run `make generator2`.

To compile all files (main DFS program, as well as both generator programs), run `make all`.

To run the first generator program, run `./generator <input.txt>`, where input.txt is the name of the graph generated by the program, to be inputted into dfs.cpp.

To run the second generator program, run `./generator2 <input.txt>`, where input.txt is the name of the binary tree generated by the program, to be inputted into dfs.cpp.

To run the DFS program, run `./dfs <input.txt>`, where input.txt is the file containing the graph structure, as outputted by one of the generator programs.

Three input files are provided as an example. The first one creates a simple graph with only six nodes, as described in our presentation. The second one is a much larger graph generated by generator.cpp, which contains 100,000 nodes. The third one is a binary tree with 1,000,000 nodes, created by generator2.cpp.
