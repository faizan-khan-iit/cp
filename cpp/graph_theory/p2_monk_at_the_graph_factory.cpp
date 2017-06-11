/*
The Monk's Job is to Identify whether the incoming graph is a tree or not. He is given N, the number of vertices in the graph and the degree of each vertex.

Find if the graph is a tree or not.
*/
#include <iostream>
using namespace std;

int degrees_of_nodes[1000] = {0};

int main(){
    int n;
    cin >> n;
    int degree_node, sum_of_degrees = 0;
    bool is_tree = true;
    for(int i=0; i<n; i++){
        cin >> degree_node;
        if(degree_node < 0){
        	cout << "No";
        	is_tree = false;
        	break;
        }
        sum_of_degrees += degree_node;
    }
    if(is_tree && (sum_of_degrees/2 == n-1)){
    	cout << "Yes";
    }else{
    	cout << "No";
    }
	return 0;
}
