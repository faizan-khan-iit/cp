/*
Lucky numbers are those numbers which contain exactly two set bits.
Find sum of those numbers which exactly contain two set bits upto a given number N.
*/
// Partially solved
#include <iostream>
#include <cmath>
using namespace std;

long long sum_upto_k_bits[1000] = {0}; // To store sum upto n bits
long long modulo = 1000000007;
long long find_sum(long long n);
int find_num_bits(long long n);
long long find_sum_upto_k_bits(int k);

int main(){
	ios::sync_with_stdio(false); // optimises input and output for faster performance
	int t=0; // test cases
	cin >> t;
	for(int i=0; i< 1000; i++){
        sum_upto_k_bits[i] = -1;
	}
	long long n;
	for(int l=0; l<t; l++){
		cin >> n;
		find_sum(n);
	}
	return 0;
}


// Find number of bits in binary representation
int find_num_bits(long long n){
	int num_bits = 0;
	while(n){
		n = n >> 1;
		num_bits++;
	}
	return(num_bits);
}

// Find sum of all numbers with two 1s upto k bits
long long find_sum_upto_k_bits(int k){
	if(k < 2){
		return 0;
	}
	if(k == 2){
        sum_upto_k_bits[k] = 3;
		return(3);
	}
	if(sum_upto_k_bits[k] != -1){
		return(sum_upto_k_bits[k]);
	}

	// Sum for kth bit
	long long sum_k = 0;
	for(int i=0; i<k-1; i++){
		sum_k += pow(2, k-1) + pow(2, i);
	}
	// Total sum upto k = kth sum + sum upto k-1th bit
	sum_upto_k_bits[k] = (sum_k + find_sum_upto_k_bits(k-1)) % modulo;
	return(sum_upto_k_bits[k]);
}

long long find_sum(long long n){
	int num_bits = find_num_bits(n);
	if(num_bits < 2){
		return(0);
	}
	// Sum upto num_bits-1 bits
	long long sum_upto_num_bits_minus_1 = find_sum_upto_k_bits(num_bits-1);
	long long ans = 0, ans1;
	// Sum for num_bit-th bit upto number n
	for(int i=0; i<num_bits-1; i++){
		ans1 = pow(2, num_bits-1) + pow(2, i);
		if(ans1 > n){
			break;
		}
		ans = (ans + ans1) % modulo;
	}
	ans = ans + sum_upto_num_bits_minus_1;
	cout << (ans % modulo) << endl;
	return(ans % modulo);
}
