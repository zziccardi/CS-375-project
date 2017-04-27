
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int nodes = 100;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	ofstream outputFile(argv[1]);
	
	if (outputFile.is_open()) {
	    outputFile << nodes << endl;
	    
	    for (int i = 0; i < nodes; i++) {
	        int numChildren = rand() % 10 + 1;
	        
	        for (int j = 0; j < numChildren; j++) {
	            outputFile << rand() % nodes;
	            
	            if (j != numChildren - 1) {
	                outputFile << ",";
	            }
	        }
	        
	        outputFile << endl;
	    }
	    
	    outputFile.close();
	}
}

