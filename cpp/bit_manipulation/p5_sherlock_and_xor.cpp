/*
You are given an array A1,A2...AN. You have to tell how many pairs (i, j)
exist such that 1 ≤ i < j ≤ N and Ai XOR Aj is odd.
*/
#include <iostream>
using namespace std;
long long arr[100000];
long long calculate_pairs(long long arr[], long long n);
long long calculate_pairs_2(long long arr[], long long n);

int main(){
	int t=0; // test cases
	cin >> t;
	long long n=0;
	for(int l=0; l<t; l++){
		cin >> n;
		for(long long j=0; j<n; j++){
			cin >> arr[j];
		}
		calculate_pairs_2(arr, n);
	}
	return 0;
}

// Naive method
long long calculate_pairs(long long arr[], long long n){
	long long pairs = 0;
	long long k;
	for(long long i=0; i<n-1; i++){
		for(long long j=i+1; j<n; j++){
			k = arr[i] ^ arr[j];
			if((k&1) != 0){
				pairs++;
			}
		}
	}
	cout << pairs << endl;
	return(pairs);
}

// Calculate number of odd and even number
// A XOR B is odd only when A is odd and B is even or vice versa
// So ans = num_odd * num_even
long long calculate_pairs_2(long long arr[], long long n){
	long long even = 0;
	for(int i=0; i<n; i++){
		if((arr[i]&1) == 0){
			even++;
		}
	}
	long long ans = even * (n-even);
	cout << ans << endl;
	return(ans);
}