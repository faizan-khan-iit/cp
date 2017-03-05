#include <iostream>
using namespace std;

int arr[100];
int find_subset_xor(int n);

int main(){
	int t; //test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> arr[j];
		}
		find_subset_xor(n);
	}
	return 0;
}

// Each element occurs 2^(n-1) times
// So XOR is always zero for n>1
int find_subset_xor(int n){
	if(n == 1){
		cout << arr[0] << endl;
		return(arr[0]);
	}
	cout << 0 << endl;
	return(0);
}
