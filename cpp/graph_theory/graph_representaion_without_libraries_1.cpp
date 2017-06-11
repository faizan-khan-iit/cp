#include <iostream>
using namespace std;

struct Node{
	int data = 0;
	Node* next = nullptr;
};

Node* head_arr[1000] = {nullptr};
Node* getNewNode(int data_i);      // Gives a pointer to a new adjacency list node
int add_edge_in_graph(int from_node, int to_node);
int remove_edge_from_graph(int from_node, int to_node);
int printGraph(int till_node);
bool edge_exists(int from_node, int to_node); // Return true if an edge exists between the two nodes

int main(){
	cout << "Enter some number" << endl;
    int a = 0;
    cin >> a;

    cout << "Creating Graph..." << endl << endl;
    add_edge_in_graph(1, 2);
    add_edge_in_graph(1, 3);
    add_edge_in_graph(1, 4);
    add_edge_in_graph(1, 5);
    add_edge_in_graph(2, 3);
    add_edge_in_graph(2, 4);
    add_edge_in_graph(2, 5);
    add_edge_in_graph(3, 4);
    add_edge_in_graph(3, 5);
    add_edge_in_graph(4, 5);

    printGraph(6);

    cout << endl << "Removing nodes" << endl << endl;

    remove_edge_from_graph(1, 2);
    remove_edge_from_graph(1, 4);
    remove_edge_from_graph(2, 1);
    remove_edge_from_graph(2, 6);
    remove_edge_from_graph(2, 2);
    remove_edge_from_graph(4, 5);
    remove_edge_from_graph(5, 6);

    printGraph(6);


    cout << endl << "Adding nodes" << endl << endl;

    add_edge_in_graph(1, 5);
    add_edge_in_graph(1, 6);
    printGraph(6);
    return (0);
	return 0;
}


Node* getNewNode(int data_i){
	Node* temp = new Node();
	temp->data = data_i;
	return(temp);
}

int add_edge_in_graph(int from_node, int to_node){
    if(edge_exists(from_node, to_node)){
        cout << "An edge already exists between " << from_node << " ---> " << to_node << endl;
        return(1);
    }
	Node* temp = getNewNode(to_node);
	temp->next = head_arr[from_node];
	head_arr[from_node] = temp;
	return(0);
}


int remove_edge_from_graph(int from_node, int to_node){
	Node* temp1 = nullptr;
	Node* temp2 = nullptr;
	bool edge_deleted = false;
	temp1 = head_arr[from_node];

	// Special case: Delete from head
	if(head_arr[from_node] != nullptr && temp1->data == to_node){
		temp2 = head_arr[from_node]-> next;
		head_arr[from_node] = temp2;
		delete(temp1);
		edge_deleted = true;
		return(0);
	}

	// Else delete from anywhere
	while(temp1 != nullptr){
		temp2 = temp1 -> next;
		if(temp2!= nullptr && temp2->data == to_node){
			temp1->next = temp2->next;
			delete(temp2);
			edge_deleted = true;
			break;
		}
		temp1 = temp1->next;
	}

	if(!edge_deleted){
		cout << endl << "Edge from node " << from_node << " to node " << to_node << " does not exist" << endl;
		return 1;
	}
	return 0;
}

// Prints all the adjacency list for each node till the node specified
int printGraph(int till_node){
    cout << endl;
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
                cout << temp->data << " ---> ";
                temp = temp->next;
            }
            cout << "!!!";
        }
        cout << endl;
    }
    return 0;
}


bool edge_exists(int from_node, int to_node){
    Node* temp = nullptr;
    temp = head_arr[from_node];
    if(temp == nullptr){
        return(false);
    }

    while(temp != nullptr){
        if(temp->data == to_node){
            return(true);
        }
        temp = temp->next;
    }
    return(false);
}
