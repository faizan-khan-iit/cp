/*
Given two numbers A and B. Find the value of pair (P,Q) such that
A <= P < Q <= B
value of P AND Q is maximum where AND is a binary operator.
*/
#include <iostream>
using namespace std;

long long calculate_max_and(long long a, long long b);

int main(){
	int t= 0; //test cases
	cin >> t;
	long long a, b;
	for(int l=0; l<t; l++){
		cin >> a;
		cin >> b;
		calculate_max_and(a, b);
	}
	return 0;
}

long long calculate_max_and(long long a, long long b){
	if(b-a == 1){
		cout << (b & a) << endl;
		return(b & a);
	}
	// Handles both odd and even cases
	// Highest set bits get priority
	long long ans = max(b & (b-1), (b-1) & (b-2));
	cout << ans << endl;
	return(ans);
}
