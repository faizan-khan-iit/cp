/*
The problem is straight and simple.
Given a number X,find how many positive
A(A>0) exists, such that
1. (A + X) = (A XOR X)
2. A < X
*/
#include <iostream>
#include <algorithm>
using namespace std;

int count_ans(int n);
int count_ans_bit(int n);

int main(){
	int t = 0; //test cases
	cin >> t;
	int n;
	for(int i=0; i<t; i++){
		cin >> n;
		count_ans_bit(n);
	}
	return 0;
}

// Naive method
int count_ans(int n){
	int ans = 0;
	for(int i=1; i<n; i++){
		if((i^n) == (i+n)){
			ans++;
		}
	}
	cout << ans << endl;
	return(ans);
}

// Bit manipulation
// Find number of zeroes in binary representation of n
// ans is (2^n) - 1
// For every 1 in n, we can only have 0 in ans
// For every 0 in n, we can have 0 or 1
// Disregard case of all 0s
int count_ans_bit(int n){
	int z = 0;
	while(n){
		// If last bit is 0
		if((n&1) == 0){
			z++;
		}
		n = n >> 1; // Divide by two
	}
	int ans = std::pow (2, z) - 1;
	cout << ans << endl;
	return(ans);
}
