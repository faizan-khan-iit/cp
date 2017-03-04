/*
Find the number of bits whose status is different in the binary representation of M and P,
i.e. , count of bits that are ,either set in M and unset in P or set in P and unset in M.
*/
#include <iostream>
using namespace std;

int find_diff_bits(long long p, long long m);

int main(){
	int t=0; // test cases
	cin >> t;
	long long p, m;
	for(int l=0; l<t; l++){
		cin >> p;
		cin >> m;
		find_diff_bits(p, m);
	}
	return 0;
}

int find_diff_bits(long long p, long long m){
	if(p == m){
		cout << 0 << endl;
		return(0);
	}
	// Take XOR and count set bits
	long long p_xor_m = p^m;
	int ans = 0;
	while(p_xor_m){
		if((p_xor_m&1) == 1){
			ans++;
		}
		p_xor_m = p_xor_m >> 1;
	}
	cout << ans << endl;
	return(ans);
}
