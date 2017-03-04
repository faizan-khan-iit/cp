/*
Micro's wife Mini gave him a bag having N strings of length N. All the strings are
binary i.e. made up of 1's and 0's only. All the strings in the bag can be generated
by a string S by simply performing right rotations N times. For example if 
S is "101", then the strings in the bag will be "110", "011", "101".
Now Mini wants to know the number of ways of selecting one string from the bag with
an odd decimal equivalent.
*/
#include <iostream>
#include <string>
using namespace std;

long long find_num_strings(int n, string s);

int main(){
	int t=0; //test cases
	cin >> t;
	int n;
	string s;
	for(int l=0; l<t; l++){
		cin >> n;
		cin >> s;
		find_num_strings(n, s);
	}
	return 0;
}

// Just count number of 1s, they will be present at last bit
long long find_num_strings(int n, string s){
	int num_ones = 0;
	for(int j=0; j<s.length(); j++){
		if(s[j] == '1'){
			num_ones++;
		}
	}
	cout << num_ones << endl;
	return(num_ones);
}
