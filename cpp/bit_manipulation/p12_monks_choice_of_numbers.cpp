/*
The Monk is given N numbers and has to select K of these numbers. For each number
that Monk chooses, he will get as many cheesecakes as the number of 1's in the
Binary representation of the number i.e. the number of bits that are set.
Help Monk find the maximum number of cakes that he can have.
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long find_max_k(int n, int k);

int main(){
	int t=0; // test cases
	cin >> t;

	int n, k;
	for(int l=0; l<t; l++){
		cin >> n;
		cin >> k;
		find_max_k(n, k); 
	}
	return 0;
}

long long find_max_k(int n, int k){
	int arr[1000];
	int ans[1000] = {0};
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int num_ones;
	// count number of ones for every number
	for(int i=0; i<n; i++){
		num_ones = __builtin_popcount(arr[i]);
		ans[i] = num_ones;
	}
	// Sort and take sum of largest k
	sort(ans, ans + n);
	long long sum = 0;
	for(int j=n-1; j>n-k-1; j--){
		sum+=ans[j];
	}
	cout << sum << endl;
	return(sum);
}
