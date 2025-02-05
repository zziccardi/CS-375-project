
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

struct timeval startTime;
struct timeval stopTime;

// Class used to represent a Node's adjacent nodes within a linked list
class ListItem {
    public:
        // index of Node in array
        int       id;
        ListItem* next;
        
        ListItem(int id) {
            this->id = id;
            next     = NULL;
        }
};

// Class used to represent each node within the adjacency list
class Node {
    public:
        string    color;
        ListItem* head;
    
        Node() {
            color = "white";
            head  = NULL;
        }
        
        void addItem(int id) {
            ListItem* item = new ListItem(id);
            
            if (head == NULL) {
                head = item;
                return;
            }
            
            ListItem* temp = head;
            
            while (temp->next != NULL) {
                temp = temp->next;
            }
            
            temp->next = item;
        }
};

// adjacency list
Node* array;
int   nodeCount = 0; // size of array

// print the adjacency list
void debugArray() {
    for (int i = 0; i < nodeCount; i++) {
        cout << i << ": ";
        
        ListItem* temp = array[i].head;
        
        while (temp != NULL) {
            cout << temp->id << " ";
            
            temp = temp->next;
        }
        
        cout << endl;
    }
}

// Prints the time taken by the algorithm in microseconds
void printTimeDifference() {
    long seconds      = stopTime.tv_sec  - startTime.tv_sec;
    long microseconds = stopTime.tv_usec - startTime.tv_usec;
    
    if (microseconds < 0) {
        seconds--;
    }
    
    long totalMicroseconds = (seconds * 1000000) + abs(microseconds);
    
    cout << "Total microseconds: " << totalMicroseconds << endl;
}

// Recursive function which implements the DFS-Visit functionality of the algorithm
void explore(Node& current) {
	current.color = "gray";
	ListItem* temp = current.head;

	while (temp != NULL) {
		if (array[temp->id].color == "white") {
			explore(array[temp->id]);
		}
		else {
			break;
		}
		temp = temp->next;
	}
	current.color = "black";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Need one argument (input file)\n");
        exit(EXIT_FAILURE);
    }
    
    // Open the graph input file specified on the command line
    ifstream inputFile(argv[1]);
    
    nodeCount = 0;
    
    if (inputFile.is_open()) {
        string line;
        
        // Get just the first line, which contains only the number of nodes to create
        getline(inputFile, line);
        
        nodeCount = stoi(line, NULL, 10);
        
        // Dynamically allocate the array of nodes based on the inputted node count
        array = new Node[nodeCount];
        
        int whichIndex = 0;
        
        // Start parsing the file from line 2
        while (getline(inputFile, line)) {
            Node n;
            
            array[whichIndex] = n;
            
            int startIndex = 0;
            int endIndex   = 0;
            
            // Parse each adjacent node for this Node's linked list
            for (int i = 0; i < line.size(); i++) {
                // Get the number of adjacent nodes to create (specified before each comma)
                if (line[i] == ',') {
                    endIndex = i;
                    
                    string sub = "";
                    
                    for (int j = startIndex; j < endIndex; j++) {
                        sub += line[j];
                    }
                    
                    startIndex = endIndex + 1;
                    
                    array[whichIndex].addItem(stoi(sub, NULL, 10));
                }
                // If it's the last number on the line, there isn't a comma afterward
                else if (i == line.size() - 1) {
                    string sub = "";
                    
                    for (int j = startIndex; j < line.size(); j++) {
                        sub += line[j];
                    }
                    array[whichIndex].addItem(stoi(sub, NULL, 10));
                }
            }
            
            whichIndex++;
        }
        
        inputFile.close();
    }
    else {
        fprintf(stderr, "Could not open input file\n");
        exit(EXIT_FAILURE);
    }
    
    cout << "Testing with " << nodeCount << " nodes" << endl;
    
    // Start timing the DFS algorithm once all parsing is done
    if (gettimeofday(&startTime, NULL) == -1) {
        perror("gettimeofday failed");
    }
    
    // Outer for loop of the DFS algorithm
    for (int i = 0; i < nodeCount; i++) {
    	//cout << i << endl;
    	if (array[i].color == "white") {
    		explore(array[i]);
    	}
    }
    
    // Stop timing the program after the algorithm has finished
    if (gettimeofday(&stopTime, NULL) == -1) {
        perror("gettimeofday failed");
    }
    
    printTimeDifference();

    //debugArray();
}

