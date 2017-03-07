#include <iostream>
using namespace std;

int arr[100000];
int find_max_cars(int n);

int main(){
	int t; // test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		find_max_cars(n);
	}
	return 0;
}

// Keep decreasing speed in array
int find_max_cars(int n){
	int max_cars = 1;
	for(int i=1; i<n; i++){
		if(arr[i] > arr[i-1]){
			arr[i] = arr[i-1];
		}else{
			max_cars++;
		}
	}
	cout << max_cars << endl;
	return(max_cars);
}
