/*
You are given a number Z and a set S with N elements.
Your job is to find a sub set of S such that the AND of the given number
and this subset is zero. If this sub set is possible print "Yes" otherwise print "No"
*/
#include <iostream>
using namespace std;

bool find_and_of_subset(int n, long long z);
long long arr[10000] = {};
	
int main(){
	int t=0; //test cases
	cin >> t;
	int n;
	long long z;
	for(int l=0; l<t; l++){
		cin >> z;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		find_and_of_subset(n, z);
	}
	return 0;
}

// Take AND of all elements. Break as soon as zero
bool find_and_of_subset(int n, long long z){
	for(int i=0; i<n; i++){
		z = (z&arr[i]);
		if(!z){
			cout << "Yes" << endl;
			return(true);
		}
	}
	cout << "No" << endl;
	return(false);
}
