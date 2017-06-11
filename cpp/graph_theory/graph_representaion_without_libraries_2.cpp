// Graph implementation using Adjacency List without any libraries

// Improvement: We could store the deletion information in the zeroeth node
#include <iostream>
using namespace std;


// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};

bool deleted_edge = false;         // If an edge has been deleted anywhere in the node -> True
Node* head_arr[1000] = {nullptr};  // Stores head pointers of all graph nodes. Nodes in graph start from 1
Node* getNewNode(int data_i);      // Gives a pointer to a new adjacency list node
int add_edge_in_graph(int from_node, int to_node);
int remove_edge_from_graph(int from_node, int to_node);
int printGraph(int till_node);


int main(){
    cout << "Enter some number" << endl;
    int a = 0;
    cin >> a;
    add_edge_in_graph(1, 2);
    add_edge_in_graph(1, 3);
    add_edge_in_graph(1, 4);
    add_edge_in_graph(2, 3);
    add_edge_in_graph(2, 5);
    add_edge_in_graph(3, 4);
    add_edge_in_graph(4, 3);
    add_edge_in_graph(4, 5);

    cout << "Graph created" << endl << endl;

    printGraph(6);

    cout << endl << "Removing nodes" << endl << endl;
    
    remove_edge_from_graph(1, 3);
    remove_edge_from_graph(1, 2);
    remove_edge_from_graph(4, 3);
    printGraph(6);


    cout << endl << "Adding nodes" << endl << endl;

    add_edge_in_graph(1, 5);
    add_edge_in_graph(1, 6);
    printGraph(6);
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
    // If somewhere an edge has been deleted, it has been set to zero
    // If this is in this node's adjacency list, find it and use it to
    // store a new edge. No need to create a new node in list
    if(deleted_edge){
        temp = head_arr[from_node];
        while(temp != nullptr){
            // Previously the edge was deleted from this list
            if(temp->data == 0){
                temp->data = to_node;
                return 0;
            }
            temp = temp->next;
        }
    }
    // If there is no 0 value, create a new node and assign it the new edge
    temp = getNewNode(to_node);
    temp->next = head_arr[from_node];
    head_arr[from_node] = temp;
    return(0);
}


// Removes an egde from the graph
int remove_edge_from_graph(int from_node, int to_node){
    Node* temp = nullptr;
    temp = head_arr[from_node];
    while(temp != nullptr){
        // Find the node to which the edge has to be deleted
        // and make that node to zero. We avoid allocation
        // and further deallocation later
        if(temp->data == to_node){
            temp->data = 0;
            break;
        }
        temp = temp->next;
    }
    // We have deleted at least one edge in graph
    deleted_edge = true;
    return 0;
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
