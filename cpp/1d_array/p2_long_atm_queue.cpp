#include <iostream>
using namespace std;

int arr[1000000];
int find_groups(int n);

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	find_groups(n);
	return 0;
}

// Check when the next element is smaller
int find_groups(int n){
	int groups=1;
	for(int i=0; i<n-1; i++){
		if(arr[i] > arr[i+1]){
			groups++;
		}
	}
	cout << groups << endl;
	return(groups);
}
