#include <iostream>
using namespace std;

int num_pairs(int n);

int main(){
    int t; // test cases
    cin >> t;
    int n = 0;
    for(int i=0; i<t; i++){
    	cin >> n;
    	num_pairs(n);
    }
	return 0;
}

// Count number of pairs where bitwise XOR is not greater than n
// Naive method
int num_pairs(int n){
	int count_pairs = 0;
	for(int i=1; i<=n-1;i++){
		for(int j=i+1; j<=n; j++){
			if((i ^ j) <= n){
				count_pairs++;
			}
		}
	}
	cout << count_pairs << endl;
	return(count_pairs);
}
