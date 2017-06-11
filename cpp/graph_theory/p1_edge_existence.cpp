#include <iostream>
using namespace std;


// Define Node data type for Adjacency List
struct Node{
    int data = 0;         // Stores the node to which a node in a graph is connected
    Node *next = nullptr; // Link to next node
};

bool deleted_edge = false;         // If an edge has been deleted anywhere in the node -> True
Node* head_arr[1010] = {nullptr};  // Stores head pointers of all graph nodes. Nodes in graph start from 1
Node* getNewNode(int data_i);      // Gives a pointer to a new adjacency list node
int add_edge_in_graph(int from_node, int to_node);
bool edge_exists(int from_node, int to_node); // Returns true if an edge exists from A to B

int main(){
    int n,m;
    cin >> n;
    cin >> m;

    int from_node, to_node;
    for(int i=0; i<m; i++){
        cin >> from_node;
        cin >> to_node;
        add_edge_in_graph(min(from_node, to_node), max(from_node, to_node));
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> from_node;
        cin >> to_node;
        if(edge_exists(min(from_node, to_node), max(from_node, to_node))){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
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

// Returns true if an edge exists from A to B
bool edge_exists(int from_node, int to_node){
    Node* temp = nullptr;
    temp = head_arr[from_node];

    // Empty list
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

