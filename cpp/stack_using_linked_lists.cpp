// Stack without libraries
#include <iostream>
using namespace std;

// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};

Node* front = nullptr;  // For Push and Pop

Node* getNewNode(int x);  // Get pointer to a newly created node
int Push(int x);          // Insert a new element at head
int Pop();                // Remove an element from head and return value, -1 if empty
int Top(int n);           // Returns top element in stack, -1 if empty
bool isEmpty();           // TRUE if stack is empty
int printStack(int n);    // Print the stack
int testStack();

int main(){
	testStack();
	return(0);
}

Node* getNewNode(int x){
	Node* temp = new Node();
	temp->data = x;
	return(temp);
}

int Push(int x){
	Node* temp = getNewNode(x);
	// Add first element
	if(isEmpty()){
		front = temp;
	}
	// Add a new element at head
	else{
		temp->next = front;
		front = temp;
	}
	return(0);
}

int Pop(){
	if(isEmpty()){
		cout << endl << "No element in stack to Pop" << endl;
		return(-1);
	}else{
		// Delete the first node
		Node* temp = front;
		int return_ans = temp->data;
		front = front->next;
		delete(temp);
		return(return_ans);
	}
	return(0);
}

int Top(int n){
	cout << endl << "Call from Top(" << n <<"): ";
	if(isEmpty()){
		cout << "No element in stack" << endl;
		return(-1);
	}else{
		cout << "Top of stack is: " << front->data << endl;
		return(front->data);
	}
}

bool isEmpty(){
	return(front == nullptr);
}

int printStack(int n){
	cout << endl << "Call from printStack(" << n <<"): ";
	if(isEmpty()){
		cout << "No element to print" << endl;
		return(-1);
	}else{
		Node* temp = front;
		while(temp != nullptr){
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	return(0);
}

int testStack(){
	printStack(1);
	Top(1);

	Pop();
	printStack(2);
	Top(2);

	for(int i=1; i<=10; i++){
		Push(i);
	}

	printStack(3);
	Top(3);

	for(int i=0; i<=10; i++){
		Pop();
	}

	printStack(4);
	Top(4);

	Push(11);
	Pop();

	printStack(5);
	Top(5);

	return(0);
}
