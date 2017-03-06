#include <iostream>
using namespace std;

int arr[10000];
bool has_zero_sequence(int n, long long sum);

int main(){
	int n;
	cin >> n;
	long long sum = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	has_zero_sequence(n, sum);
	return 0;
}

bool has_zero_sequence(int n, long long sum){
	// If only element is not zero
	if((n<2) && (sum>0)){
		cout << "NO" << endl;
		return(0);
	}
	// If sum is odd, no use computing
	if((sum & 1) != 0){
		cout << "NO" << endl;
		return(false);
	}
	// Decrease from element 1
	for(int i=0; i < n-1; i++){
		if(arr[i] < 0){
			cout << "NO" << endl;
			return(false);
		}
		while(arr[i] > 0){
			arr[i]--;
			arr[i+1]--;
		}
	}
	// Check last element separately
	if(arr[n-1] < 0){
		cout << "NO" << endl;
		return(false);
	}
	cout << "YES" << endl;
	return(true);
}
