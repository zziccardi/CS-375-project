
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int nodeCount = 100000000;

int main(int argc, char* argv[]) {
    if (argc != 2) {
	    fprintf(stderr, "This program requires a single argument: the file name for the generated input data\n");
	    exit(EXIT_FAILURE);
	}
	
	ofstream outputFile(argv[1]);
	
	if (outputFile.is_open()) {
	    outputFile << nodeCount << endl;
	    
	    int nodesWritten = 0;
	    
	    for (int i = 0; i < nodeCount; i++) {
	        if (nodesWritten+2 < nodeCount) {
	            int writeMe = 2 * i + 1;
	            
	            outputFile << writeMe     << ",";
	            outputFile << writeMe + 1 << endl;	        
	        }
	        else {
	            outputFile << endl;
	        }
	        
	        nodesWritten += 2;
	    }
	    
	    outputFile.close();
	}
}

