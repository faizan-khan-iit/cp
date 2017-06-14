// DFS without libraries
#include <iostream>
using namespace std;
#define STACK_SIZE 1000

// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};


// Graph creation functions
Node* head_arr[STACK_SIZE] = {nullptr};  // Stores head pointers of all graph nodes. Nodes in graph start from 1
Node* getNewNode(int data_i);            // Gives a pointer to a new adjacency list node
int add_edge_in_graph(int from_node, int to_node);
int printGraph(int till_node);
int createGraph(int num_graph);

// Stack Manipulation Functions using Arrays
int front_of_stack = -1;
int Stack[STACK_SIZE] = {0};
int Visited[STACK_SIZE] = {0};
int Push(int x);
int Pop(int x);
int Top();
bool isEmpty();
bool isFull();
int printStack();
int TestStack();

// DFS Functions
int dfs_recursive(int source_node);
int dfs_iterative(int source_node);
int dfs(int source_node, int method){
	if(method == 0){
		cout << "Recursive:" << endl;
		return(dfs_recursive(source_node));
	}else{
		cout << "Iterative: " << endl;
		return(dfs_iterative(source_node));
	}
	return(0);
}
int main(){
	createGraph(4);
	printGraph(14);
	dfs(1, 1);
	// TestStack();
    return (0);
}

Node* getNewNode(int data_i){
    Node* temp = new Node();
    temp->data = data_i;
    return(temp);
}


// Insert a new edge in graph from node A to B
int add_edge_in_graph(int from_node, int to_node){
    Node * temp = nullptr;
    temp = getNewNode(to_node);
    temp->next = head_arr[from_node];
    head_arr[from_node] = temp;
    return(0);
}

// Prints all the adjacency list for each node till the node specified
int printGraph(int till_node){
    Node* temp = nullptr;
    till_node = min(till_node, 999);
    for(int i=0; i<=till_node; i++){
        cout << i << " ---> ";
        temp = head_arr[i];
        // Empty list -> No node has been connected to this node
        if(temp == nullptr){
            cout << "??";
        }else{
            while(temp != nullptr){
                // If some data is zero, we don't see it as a connection
                // Just some implementation quirk
                if(temp->data != 0){
                    cout << temp->data << " ---> ";
                }
                temp = temp->next;
            }
            cout << "!!!";
        }
        cout << endl;
    }
    return 0;
}

int createGraph(int num_graph){
	if(num_graph == 1){
		add_edge_in_graph(1, 2); add_edge_in_graph(2, 1);
		add_edge_in_graph(1, 3); add_edge_in_graph(3, 1);
		add_edge_in_graph(2, 4); add_edge_in_graph(4, 2);
		add_edge_in_graph(2, 5); add_edge_in_graph(5, 2);
		add_edge_in_graph(3, 6); add_edge_in_graph(6, 3);
		add_edge_in_graph(3, 7); add_edge_in_graph(6, 3);
		add_edge_in_graph(4, 8); add_edge_in_graph(8, 4);
		add_edge_in_graph(4, 9); add_edge_in_graph(9, 4);
		add_edge_in_graph(5, 10); add_edge_in_graph(10, 5);
		add_edge_in_graph(5, 11); add_edge_in_graph(11, 5);
		add_edge_in_graph(5, 12); add_edge_in_graph(12, 5);
		add_edge_in_graph(5, 13); add_edge_in_graph(13, 5);	
	}else if(num_graph == 2){
		add_edge_in_graph(1, 3); add_edge_in_graph(3, 1);
		add_edge_in_graph(1, 5); add_edge_in_graph(5, 1);
		add_edge_in_graph(2, 3); add_edge_in_graph(3, 2);
		add_edge_in_graph(2, 6); add_edge_in_graph(6, 2);
		add_edge_in_graph(3, 5); add_edge_in_graph(5, 3);
		add_edge_in_graph(3, 4); add_edge_in_graph(4, 3);
		add_edge_in_graph(3, 6); add_edge_in_graph(6, 3);
		add_edge_in_graph(4, 6); add_edge_in_graph(6, 4);
		add_edge_in_graph(5, 6); add_edge_in_graph(6, 5);
	}else if(num_graph == 3){
		add_edge_in_graph(1, 2); add_edge_in_graph(2, 1);
		add_edge_in_graph(1, 3); add_edge_in_graph(3, 1);
		add_edge_in_graph(2, 4); add_edge_in_graph(4, 2);
		add_edge_in_graph(2, 5); add_edge_in_graph(5, 2);
		add_edge_in_graph(2, 6); add_edge_in_graph(6, 2);
		add_edge_in_graph(3 ,7); add_edge_in_graph(7, 3);
		add_edge_in_graph(7, 8); add_edge_in_graph(8, 7);
		add_edge_in_graph(8, 9); add_edge_in_graph(9, 8);
	}else if(num_graph == 4){
		add_edge_in_graph(1, 2); add_edge_in_graph(2, 1);
		add_edge_in_graph(1, 3); add_edge_in_graph(3, 1);
		add_edge_in_graph(2, 4); add_edge_in_graph(4, 2);
		add_edge_in_graph(3, 4); add_edge_in_graph(4, 3);
		add_edge_in_graph(3, 5); add_edge_in_graph(5, 3);
		add_edge_in_graph(4, 6); add_edge_in_graph(6, 4);
	}
	return(0);
}


int Push(int x){
	if(isFull()){
		cout << "No more pushes allowed" << endl;
		return(-1);
	}
	Stack[++front_of_stack] = x;
	return(front_of_stack);
}

int Pop(){
	if(isEmpty()){
		cout << "No elements to pop" << endl;
		return(-1);
	}
	int ans = Stack[front_of_stack];
	front_of_stack--;
	return(ans);
}

int Top(){
	if(isEmpty()){
		cout << "No elements in Stack" << endl;
		return(-1);
	}
	return(Stack[front_of_stack]);
}

bool isEmpty(){
	return(front_of_stack == -1);
}

bool isFull(){
	return(front_of_stack == (STACK_SIZE-1));
}


int dfs_recursive(int source_node){
	Visited[source_node] = 1;
	cout << endl << "Visited Node: " << source_node;
	Node* temp = head_arr[source_node];
	int neighbour = 0;
	while(temp != nullptr){
		neighbour = temp->data;
		if(Visited[neighbour] == 0){
			dfs_recursive(neighbour);
		}
		temp = temp->next;
	}
	return(0);
}

int dfs_iterative(int source_node){
	Push(source_node);
	int current_node, neighbour;
	Visited[source_node] = 1;
	
	while(!isEmpty()){
		current_node = Top();
		Pop();
		cout << endl << "Visited Node: " << current_node;
		Node* temp = head_arr[current_node];
		while(temp != nullptr){
			neighbour = temp->data;
			if(Visited[neighbour] == 0){
				Push(neighbour);
				Visited[neighbour] = 1;
			}
			temp = temp->next;
		}
	}
	return(0);
}

int printStack(){
	cout << "Printing stack for front = " << front_of_stack << " :";
	for(int i=0; i<=front_of_stack; i++){
		cout << "  " << Stack[i];
	}
	cout << endl << "Top: " << Top() << endl;
	return(0);
}

int TestStack(){
	printStack();

	Push(100);
	printStack();
	Pop();
	printStack();

	Pop();
	printStack();

	for(int i=100; i<110; i++){
		Push(i);
	}
	printStack();

	for(int i=0; i<11; i++){
		Pop();
	}
	printStack();
}
