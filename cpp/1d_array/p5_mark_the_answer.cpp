#include <iostream>
using namespace std;

int arr[100000];
int find_max_score(int n, int x);

int main(){
	int n, x;
	cin >> n >> x;
	for(int l=0; l<n; l++){
		cin >> arr[l];
	}
	find_max_score(n, x);
	return 0;
}

// Count until 2 elements > max_diff
int find_max_score(int n, int x){
	int ctr=0, i;
	for(i=0; i<n; i++){
		if(arr[i] > x){
			ctr++;
		}
		if(ctr>1){
			break;
		}
	}
	int ans = i - min(ctr, 1);
	cout << (ans) << endl;
	return(ans);
}
