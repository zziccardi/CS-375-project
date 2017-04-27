
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

void explore(Node& current) {
	current.color = "gray";
	ListItem* temp = current.head;

	while(temp != NULL ) {
		//cout << temp -> id << " " << array[temp->id].color << endl;
		if(array[temp->id].color == "white") {
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
    
    ifstream inputFile(argv[1]);
    
    nodeCount = 0;
    
    if (inputFile.is_open()) {
        string line;
        
        // get just the first line, which contains only the number of nodes to create
        getline(inputFile, line);
        
        nodeCount = stoi(line, NULL, 10);
        
        // dynamically allocate the array of nodes based on the inputted node count
        array = new Node[nodeCount];
        
        int whichIndex = 0;
        
        // start parsing the file from line 2
        while (getline(inputFile, line)) {
            Node n;
            
            array[whichIndex] = n;
            
            int startIndex = 0;
            int endIndex   = 0;
            
            // parse each adjacent node for this Node's linked list
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    endIndex = i;
                    
                    string sub = "";
                    
                    for (int j = startIndex; j < endIndex; j++) {
                        sub += line[j];
                    }
                    
                    startIndex = endIndex + 1;
                    
                    array[whichIndex].addItem(stoi(sub, NULL, 10));
                }
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
    
    for(int i = 0; i < nodeCount; i++) {
    	//cout << i << endl;
    	if(array[i].color == "white") {
    		explore(array[i]);
    	}
    }
    
    for(int i = 0; i < nodeCount; i++) {
    	cout << array[i].color << endl;
    }
    //debugArray();
}

