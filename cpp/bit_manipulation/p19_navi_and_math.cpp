#include <iostream>
using namespace std;

long long mod = 1000000007;
int arr[16];
long long calc_p_mod(int n);

int main(){
	int t=0; // test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		cout << "Case #" << t << " :" << calc_p_mod(n) << endl;
	}
	return 0;
}

long long calc_p_mod(int n){
	long long max_p = 0, p;
	long long sum = 0, mul;
	for(int i=2; i<=n; i++){
		for(int j=0; j<n-i+1; j++){
			sum += arr[j];
			mul *= arr[j];
		}
		p = mul/sum;
		max_p = max(p, max_p);
	}
	return((max_p % mod));
}
