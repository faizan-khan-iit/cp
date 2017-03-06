/*
Given an array A. Is there any subset of array A in which if we do AND of all
elements of that subset then output should be in power of two
(for example : 1,2,4,8,16 and so on ).
*/
#include <iostream>
using namespace std;

long long arr[200];
bool find_subset(int n);

int main(){
	int t; // test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int i=0; i<n; i++){
            cin >> arr[i];
		}
		find_subset(n);
	}
	return 0;
}

// Consider bit-wise
bool find_subset(int n){
	// If any element is power of two
	for(int i=0; i<n; i++){
		if(__builtin_popcount(arr[i]) == 1){
			cout << "YES" << endl;
			return(true);
		}
	}
	// For every bit i, take AND of all elements with ith bit set
	int ans = 0;
	for(int i=0; i<32; i++){
		// If first element is zero, AND will be zero
		for(int k=0; k<n; k++){
			if(__builtin_popcount(arr[k]) > 0){
				ans = arr[k];
				break;
			}
		}
		for(int j=0; j<n; j++){
			// Take only elements with ith bit set
			if(arr[j]&(1<<i)){
				ans = (ans & arr[j]);
			}
		}
		// If power of two
		if(__builtin_popcount(ans) == 1){
			cout << "YES" << endl;
			return(true);
		}
	}
	cout << "NO" << endl;
	return(true);
}
