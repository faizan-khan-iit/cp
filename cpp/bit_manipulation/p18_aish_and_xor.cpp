#include <iostream>
using namespace std;

int arr[100000];
int find_xor_and_bits(int n, int l, int r);

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int q, l, r;
	cin >> q;
	for(int j=0;j<q; j++){
		cin >> l;
		cin >> r;
		find_xor_and_bits(n, l, r);
	}
	return 0;
}

// Keep taking XOR and count bits
int find_xor_and_bits(int n, int l, int r){
	int ans[100000];
	int k, num_zeroes=0, xor_arr = arr[l-1];
	if(!arr[l-1]){
		num_zeroes++;
	}
	for(int i=l; i<r; i++){
		xor_arr = (xor_arr ^ arr[i]);
		if(!arr[i]){
			num_zeroes++;
		}
	}
	cout << xor_arr << " " << num_zeroes << endl;
	return(0);
}
