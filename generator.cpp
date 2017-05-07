
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

// Specify the desired number of nodes and how many adjacent nodes it should have here
int nodeCount         = 100000;
int adjacentNodeCount = 100;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	if (argc != 2) {
	    fprintf(stderr, "This program requires a single argument: the file name for the generated input data\n");
	    exit(EXIT_FAILURE);
	}
	
	ofstream outputFile(argv[1]);
	
	if (outputFile.is_open()) {
	    // Print the total number of nodes on the first line
	    outputFile << nodeCount << endl;
	    
	    // For each node, randomly generate its number of adjacent nodes in the range 0 through adjacentNodes
	    for (int i = 0; i < nodeCount; i++) {
	        int numChildren = rand() % adjacentNodeCount;
	        // Comment out the above line and un-comment the below line to not randomly generate the number of adjacent nodes within the specified range
	        //int numChildren = adjacentNodeCount;
	        
	        // Randomly generate which other node this node is adjacent to
	        for (int j = 0; j < numChildren; j++) {
	            outputFile << rand() % nodeCount;
	            
	            if (j != numChildren - 1) {
	                outputFile << ",";
	            }
	        }
	        
	        outputFile << endl;
	    }
	    
	    outputFile.close();
	}
}

