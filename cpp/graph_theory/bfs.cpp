// BFS without libraries
#include <iostream>
using namespace std;
#define QUEUE_SIZE 1001

// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};


// Graph creation functions
Node* head_arr[QUEUE_SIZE] = {nullptr};  // Stores head pointers of all graph nodes. Nodes in graph start from 1
Node* getNewNode(int data_i);            // Gives a pointer to a new adjacency list node
int add_edge_in_graph(int from_node, int to_node);
int printGraph(int till_node);
int createGraph(int num_graph);

// Queue manipulation functions using circular arrays
int front_of_queue = -1;
int rear_of_queue = -1;
int elements_in_queue = 0;
int Queue[QUEUE_SIZE] = {0};
int Enqueue(int x);
int Dequeue();
int front();
int isEmpty();
int isFull();
int printQueue(int n);
int TestQueue();
int printFront(int n);

// BFS functions
int bfs(int source_node);
int Visited[QUEUE_SIZE] = {0};

/////////////////////////////////////////////////////////////


int main(){
	createGraph(4);
	printGraph(14);
	// TestQueue();
	bfs(1);
    return (0);
}


/////////////////////////////////////////////////////////////

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

int isEmpty(){
	return(elements_in_queue == 0);
}

int isFull(){
	return(elements_in_queue == QUEUE_SIZE);
}

int Enqueue(int x){
	if(isEmpty()){
		front_of_queue = 0;
		rear_of_queue = 0;
		Queue[rear_of_queue] = x;
		elements_in_queue++;
		return(rear_of_queue);
	}
	if(isFull()){
		cout << endl << "Queue is full. Enqueue(x) not allowed" << endl;
		return(-1);
	}
	rear_of_queue = (rear_of_queue + 1) % QUEUE_SIZE;
	Queue[rear_of_queue] = x;
	elements_in_queue++;
	return(rear_of_queue);
}

int Dequeue(){
	if(isEmpty()){
		cout << "No elements to dequeue" << endl;
		return(-1);
	}
	int x = Queue[front_of_queue];
	front_of_queue = (front_of_queue + 1) % QUEUE_SIZE;
	elements_in_queue--;
	return(x);
}

int front(){
	if(isEmpty()){
		cout << "No elements in Queue" << endl;
		return(-1);
	}
	return(Queue[front_of_queue]);
}

int printQueue(int n){
	cout << endl << "printQueue(" << n << ")" << endl;
	if(isEmpty()){
		cout << "No elements to print in Queue" << endl;
		return(-1);
	}

	int i = front_of_queue;
	bool overflow = true;

	while(i < QUEUE_SIZE){
		cout << Queue[i] << "  ";
		if(i == rear_of_queue){
			overflow = false;
			break;
		}
		i++;
	}
	if(overflow){
		for(int j=0; j<=rear_of_queue; j++){
			cout << Queue[j] << "  ";
		}
	}
	cout << endl;
	return(0);
}


int TestQueue(){
	printQueue(1);
	printFront(1);

	Enqueue(100);
	printQueue(2);
	printFront(2);

	Dequeue();
	printQueue(3);
	printFront(3);

	Dequeue();
	printQueue(4);
	printFront(4);

	for(int i=90; i<100; i++){
		Enqueue(i);
	}
	printQueue(5);
	printFront(5);

	for(int i=0; i<11; i++){
		Dequeue();
	}
	printQueue(6);
	printFront(6);

	// Reduce QUEUE_SIZE to ~10 for testing below
	for(int i=80; i<85; i++){
		Enqueue(i);
	}
	printQueue(7);
	printFront(7);
    
    for(int i=0; i<3; i++){
		Dequeue();
	}
	printQueue(8);
	printFront(8);

	for(int i=70; i<78; i++){
		Enqueue(i);
	}
	printQueue(9);
	printFront(9);

	for(int i=0; i<9; i++){
		Dequeue();
	}
	printQueue(10);
	printFront(10);
	return(0);
}

int printFront(int n){
	int front_val = front();
	cout << endl << "printFront(" << n << ");" << endl;
	cout << "Front: " << front_val << "  front_of_queue: " << front_of_queue << endl;
	return(0);
}

int bfs(int source_node){
	Visited[source_node] = 1;

	Enqueue(source_node);
	int current_node, neighbour;
	while(!isEmpty()){
		current_node = front();
		Dequeue();
		cout << endl << "Visited Node: " << current_node;
		Node* temp = head_arr[current_node];
		while(temp != nullptr){
			neighbour = temp->data;
			if(Visited[neighbour] == 0){
				Enqueue(neighbour);
				Visited[neighbour] = 1;
			}
			temp = temp->next;
		}
	}
	return(0);
}
