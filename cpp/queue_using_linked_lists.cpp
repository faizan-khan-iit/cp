// Queue without libraries

#include <iostream>
using namespace std;

// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};

Node* front = nullptr;  // For Dequeueing
Node* rear = nullptr;   // For Enqueueing

Node* getNewNode(int x);// Get pointer to a newly created node
int Enqueue(int x);     // Add a new node at rear
int Dequeue();          // Remove a node from head and return value
bool isEmpty();         // TRUE if queue is empty
int frontQueue(int n);  // Returns front element of queue, -1 if empty
int printQueue(int n);  // Print the queue
int testQueue();        // For testing all possibilities

int main(){
	testQueue();
	return (0);
}

Node* getNewNode(int x){
	Node* temp = new Node();
	temp->data = x;
	return(temp);
}

int Enqueue(int x){
	Node* temp = getNewNode(x);
	// Enter first node
	if(isEmpty()){
		front = temp;
		rear = temp;
	}
	// Else set rear to newly created node
	else{
		rear->next = temp;
		rear = temp;
	}
	return(0);
}

int Dequeue(){
	if(isEmpty()){
		cout << endl << "No node to delete from queue" << endl;
		return(1);
	}
	// Only one element in queue
	else if(rear == front){
		Node* temp = front;
		rear = nullptr;
		front = nullptr;
		delete(temp);
		return(0);
	}
	// Set front to next element and delete previous node
	else{
		Node* temp = front;
		front = front->next;
		delete(temp);
		return(0);
	}
	return(-1);
}


bool isEmpty(){
	return((front == nullptr) && (rear == nullptr));
}


int frontQueue(int n){
	cout << endl << "Call from frontQueue(" << n <<"): ";
	if(!isEmpty()){
		cout << "Front of queue is: " << front->data << endl;
		return(front->data);
	}else{
		cout << "No element in queue to return" << endl;
		return(-1);
	}
	return(0);
}


int printQueue(int n){
	cout << endl << "Call from printQueue(" << n << "): ";
	if(isEmpty()){
		cout << "No element to print" << endl;
		return(-1);
	}else{
		Node* temp = front;
		while(temp!=nullptr){
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	return(0);
}

int testQueue(){
	cout << "Testing Queue" << endl;
	// Empty Queue
	if(isEmpty()){
		cout << "Initially empty" << endl;
	}

	printQueue(1);  // Should print nothing
	for(int i=1; i<=10; i++){
		Enqueue(i);
	}
	frontQueue(1);  // Should return 1

	// Non empty queue
	if(isEmpty()){
		cout << "Empty after Enqueueing" << endl;
	}
	printQueue(2); // Should print 1 to 10
	for(int j=0; j<=10; j++){
		if(j==5){
			printQueue(3);  // Should print 6 to 10
		}
		Dequeue();
	}
	printQueue(4); // Should return nothing
	frontQueue(2); // Should return nothing

	Dequeue();
	// Empty queue
	if(isEmpty()){
		cout << "Empty after Dequeueing" << endl;
	}
	frontQueue(3); // Should return nothing
	Enqueue(1);
	Dequeue();

	frontQueue(4); // Should return nothing
	printQueue(5); // Should print nothing
	return(0);
}
