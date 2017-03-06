#include <iostream>
using namespace std;

int arr[100000];
bool find_lucky(int n);

int main(){
	int t=0; //test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		find_lucky(n);
	}
	return 0;
}

// Keep a ctr with minimum element
bool find_lucky(int n){
	int min = 1000000000+1, occurs=0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if(arr[i] < min){
			min = arr[i];
			occurs = 1;
		}else if(arr[i] == min){
			occurs++;
		}
	}
	// If odd -> Lucky
	if((occurs&1)){
		cout << "Lucky" << endl;
		return(true);
	}
	cout << "Unlucky" << endl;
	return(false);
}
