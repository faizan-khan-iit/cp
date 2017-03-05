/*
Given an array of N elements, check if it is possible to obtain a sum of S,
by choosing some (or none) elements of the array and adding them.
*/
#include <iostream>
using namespace std;

int arr[15];
bool find_subset_sum(int n, int s);

int main(){
	int t; //test cases
	cin >> t;
	int n, s;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> arr[j];
		}
		cin >> s;
		find_subset_sum(n, s);
	}
	return 0;
}


bool find_subset_sum(int n, int s){
	if(s == 0){
		cout << "YES" <<endl;
		return(true);
	}
	// Brute force here
	cout << "NO" <<endl;
	return(false);
}
