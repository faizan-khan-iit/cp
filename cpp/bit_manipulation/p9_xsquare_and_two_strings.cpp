#include <iostream>
#include <string>
using namespace std;

bool find_common_subsequence(string s1, string s2);

int main(){
	int t = 0; // test cases
	cin >> t;
	string s1, s2;
	for(int l=0; l<t; l++){
		cin >> s1;
		cin >> s2;
		find_common_subsequence(s1, s2);
	}
	return 0;
}

// Find any 1 alphabet in common in two strings
bool find_common_subsequence(string s1, string s2){
	bool s_alphabets[26] = {0};
	int alpha_num = 0, alpha_done;
	
	for(int i=0; i<s1.length(); i++){
		alpha_num = s1[i] - 97;
		// Set alphabet in array if not done yet
		if(s_alphabets[alpha_num] == 0){
			s_alphabets[alpha_num] = 1;
			alpha_done++;
		}
		// If all are set, we need not consider rest of string
		if(alpha_done == 26){
			break;
		}
	}

	for(int j=0; j<s2.length(); j++){
		alpha_num = s2[j] - 97;
		// Break at first match
		if(s_alphabets[alpha_num] != 0){
			cout << "Yes" << endl;
			return(true);
		}
	}
	cout << "No" << endl;
	return(true);
}
