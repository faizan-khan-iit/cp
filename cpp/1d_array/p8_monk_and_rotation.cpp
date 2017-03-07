#include <iostream>
using namespace std;

int arr[100000];
int find_rotated_array(int n, int k);

int main(){
	int t, n, k;
	cin >> t;
	for(int l=0; l<t; l++){
		cin >> n >> k;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		find_rotated_array(n ,k);
	}
	return 0;
}

// Circular array implementation
int find_rotated_array(int n, int k){
	k = (k % n);
	int j = (n-k)%n;
	int i=j;
	bool cond = true;
	while(cond){
		cout << arr[j] << " ";
		j = (j+1)%n;
		if(j==i){
			cond = false;
		}
	}
	cout << endl;
	return(0);
}
