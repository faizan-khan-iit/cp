// BFS Using Matrix Representation

#include <iostream>
using namespace std;
typedef long long int ll;
#define QUEUE_SIZE 1001

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
// Graph Creation Funcitons
int Graph_Matrix[QUEUE_SIZE][QUEUE_SIZE] = {0};
int createGraph(int m);

// BFS functions
int bfs(int source_node, int matrix_size);
int Visited[QUEUE_SIZE] = {0};
int Level_of_nodes[QUEUE_SIZE] = {0};
int printLevelOfNodes(int till_node);


int main(){
	int n;
	cout << "Num nodes: ";
	cin >> n;
	createGraph(n);
	bfs(1, n);
	printLevelOfNodes(n);
	return 0;
}

int createGraph(int m){
	// Create graph using input
	for (int i = 1; i<=m; i++){
		for (int j = 1; j<=m; j++){
			cin >> Graph_Matrix[i][j];
		}
	}

	// Input 1: 5 nodes: ans -> 1, 2, 3, 4, 5
	// 0 1 0 0 0
	// 1 0 1 0 0
	// 0 1 0 1 0
	// 0 0 1 0 1
	// 0 0 0 1 0

	// Input 2: 11 nodes : ans -> 1, 3 5, 2 4 6 8, 7 9 10, 11
	// 0 0 1 0 1 0 0 0 0 0 0
	// 0 0 1 0 0 0 1 0 0 0 0
	// 1 1 0 1 0 0 0 0 0 0 0
	// 0 0 1 0 0 0 0 0 1 0 0
	// 1 0 0 0 0 1 0 1 0 0 0
	// 0 0 0 0 1 0 0 0 0 0 0
	// 0 1 0 0 0 0 0 0 0 0 0
	// 0 0 0 0 1 0 0 0 0 1 0
	// 0 0 0 1 0 0 0 0 0 0 0
	// 0 0 0 0 0 0 0 1 0 0 1
	// 0 0 0 0 0 0 0 0 0 1 0

	// Input 3: 7 nodes: ans -> 1, 2 3, 4 5 6 7
	// 0 1 1 0 0 0 0
	// 1 0 0 1 1 0 0
	// 1 0 0 0 0 1 1
	// 0 1 0 0 0 0 0
	// 0 1 0 0 0 0 0
	// 0 0 1 0 0 0 0
	// 0 0 1 0 0 0 0
	return(0);
}

// Queue Functins
int isEmpty(){
	return(elements_in_queue == 0);
}

int isFull(){
	return(elements_in_queue == QUEUE_SIZE);
}

int Enqueue(int x){
	if (isEmpty()){
		front_of_queue = 0;
		rear_of_queue = 0;
		Queue[rear_of_queue] = x;
		elements_in_queue++;
		return(rear_of_queue);
	}
	if (isFull()){
		cout << endl << "Queue is full. Enqueue(x) not allowed" << endl;
		return(-1);
	}
	rear_of_queue = (rear_of_queue + 1) % QUEUE_SIZE;
	Queue[rear_of_queue] = x;
	elements_in_queue++;
	return(rear_of_queue);
}

int Dequeue(){
	if (isEmpty()){
		cout << "No elements to dequeue" << endl;
		return(-1);
	}
	int x = Queue[front_of_queue];
	front_of_queue = (front_of_queue + 1) % QUEUE_SIZE;
	elements_in_queue--;
	return(x);
}

int front(){
	if (isEmpty()){
		cout << "No elements in Queue" << endl;
		return(-1);
	}
	return(Queue[front_of_queue]);
}


int bfs(int source_node, int matrix_size){
	Visited[source_node] = 1;
	Level_of_nodes[source_node] = 1; // We use this value - 1, because initialize all vals to 0

	Enqueue(source_node);
	int current_node, neighbour;
	while (!isEmpty())	{
		current_node = front();
		Dequeue();
		cout << endl << "Visited Node: " << current_node;
		for (int i = 1; i<=matrix_size; i++){
			if (Graph_Matrix[current_node][i] == 1){
				neighbour = i;
				if (Visited[neighbour] == 0){
					Enqueue(neighbour);
					Visited[neighbour] = 1;
					Level_of_nodes[neighbour] = Level_of_nodes[current_node] + 1;
				}
			}
		}
	}
	return(0);
}


int printLevelOfNodes(int till_node){
	cout << "Level of Nodes: " << endl;
	for(int i=0; i<=till_node; i++){
		// All initial levels are initialised to 0
		cout << "Node: " << i << " -> Level: " << Level_of_nodes[i] - 1 << endl;
	}
	return(0);
}
