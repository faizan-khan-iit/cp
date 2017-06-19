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
int printQueue(int n);
int TestQueue();
int printFront(int n);

// Graph Creation Funcitons
int Graph_Matrix[QUEUE_SIZE][QUEUE_SIZE] = {0};
int createGraph(int m);
int printGraph(int till_node);

// BFS functions
int bfs(int source_node, int matrix_size);
int Visited[QUEUE_SIZE] = {0};


int main(){
	int n;
	cout << "Num nodes: ";
	cin >> n;
	createGraph(n);
	// printGraph(n);
	bfs(1, n);
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

int printGraph(int till_node){
	for (int i = 1; i<=till_node; i++){
		for (int j = 1; j<=till_node; j++){
			cout << Graph_Matrix[i][j] << "  ";
		}
		cout << endl;
	}
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

int printQueue(int n){
	cout << endl << "printQueue(" << n << ")" << endl;
	if (isEmpty()){
		cout << "No elements to print in Queue" << endl;
		return(-1);
	}

	int i = front_of_queue;
	bool overflow = true;

	while (i < QUEUE_SIZE){
		cout << Queue[i] << "  ";
		if (i == rear_of_queue){
			overflow = false;
			break;
		}
		i++;
	}
	if (overflow){
		for (int j = 0; j<=rear_of_queue; j++){
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

	for (int i = 90; i<100; i++){
		Enqueue(i);
	}
	printQueue(5);
	printFront(5);

	for (int i = 0; i<11; i++){
		Dequeue();
	}
	printQueue(6);
	printFront(6);

	// Reduce QUEUE_SIZE to ~10 for testing below
	for (int i = 80; i<85; i++){
		Enqueue(i);
	}
	printQueue(7);
	printFront(7);

	for (int i = 0; i<3; i++){
		Dequeue();
	}
	printQueue(8);
	printFront(8);

	for (int i = 70; i<78; i++){
		Enqueue(i);
	}
	printQueue(9);
	printFront(9);

	for (int i = 0; i<9; i++){
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

int bfs(int source_node, int matrix_size){
	Visited[source_node] = 1;

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
				}
			}
		}
	}
	return(0);
}
