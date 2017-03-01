/*
 given N non-negative integers and he has to identify a lone integer among them.
 A lone integer is defined as an integer in the given array of integers that is
 left alone after pairing each of the other integers.
 Two integers can be paired if they have same value in decimal number system
 and have different indices in the array.It is guaranteed that there is at most
 one such integer
 NOTE: An integer can't be paired with itself and once paired it can't be
 used to pair with other integers.
*/
#include <iostream>
using namespace std;

long long lone_int(long long arr[], int n);
long long lone_int_bit(long long arr[], int n);

int main(){
    ios::sync_with_stdio(false); // optimises input and output for faster performance
	int t = 0; //test cases
	cin >> t;
	int n;
	long long arr[100000];
	for(int l=0; l<t; l++){
		cin >> n;
		//for(int k=0; k<n; k++){
		//	cin >> arr[k];
		//}
		//lone_int_bit(arr, n);
		long long ans = 0;
		long long j = 0;
		for(int k=0; k<n; k++){
			cin >> j;
			ans = ans^j;
		}
		if(ans){
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
	}
	return 0;
}

// Naive method
long long lone_int(long long arr[], int n){
	long long ans = -1;
	for(int i=0; i < n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > -1 && arr[i] == arr[j]){
				arr[i] = -1;
				arr[j] = -1;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i] > -1){
			ans = arr[i];
		}
	}
	cout << ans << endl;
	return(ans);
}

// Take bitwise XOR of all numbers
long long lone_int_bit(long long arr[], int n){
	long long ans = 0;
	for(int i=0; i<n; i++){
		ans = ans ^ arr[i];
	}
	if(ans){
        cout << ans << endl;
		return(ans);
	}
	cout << -1 << endl;
	return(-1);
}
