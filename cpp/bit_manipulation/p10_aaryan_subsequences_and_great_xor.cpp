/*
Given an array of numbers, compute the XOR of all the subsequences that can be formed.
Suppose each subsequence had their following XOR value that came out after computing
 -> {P[0], P[1], P[2], and so on upto P[2^n-1] subsequences in an array of n numbers}

Now, the resultant answer is computed by taking bitwise inclusive OR of all P[i]'s
*/
#include <iostream>
using namespace std;

long long compute_ans(int n);

int main(){
	int n = 0;
	cin >> n;
	compute_ans(n);
	return 0;
}

// Just take OR of all inputs
// They will be present as subsequences
// XOR(A) = A
// So all the other supersets of A will give less than or equal set bits of A
// Hence no need for their calculation
long long compute_ans(int n){
	long long ans = 0, ans1;
	for(int i=0; i<n; i++){
		cin >> ans1;
		ans = ans | ans1;
	}
	cout << ans << endl;
	return(ans);
}
