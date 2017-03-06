#include <iostream>
using namespace std;

int arr[20][20];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	return 0;
}
