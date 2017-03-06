#include <iostream>
#include <string>
using namespace std;

int find_num_substr(string s, string qstr);

int main(){
	int t; //test cases
	cin >> t;
	int q;
	string s, qstr;
	for(int l=0;l<t;l++){
		cin >> s;
		cin >> q;
		for(int i=0; i<q; i++){
			cin >> qstr;
			find_num_substr(s, qstr);
		}
	}
	return 0;
}

int get_index(char c){
	if(c <= 57){
		return(c - 48);
	}
	if(c <= 90){
		return((c - 65) + 10);
	}
	return((c - 97) + 36);
}

// Getting TLE in some cases
// Start with first element of s and take strings of increasing length
// As soon as first string matches qstr, all susequent strings starting with index
// also contain qstr
int find_num_substr(string s, string qstr){
	int arr[62] = {0};
	int q_len = qstr.length(), ctr=0;
	// Form array to match qstr
	// If all elements become zero, we have a match
	for(int i=0; i<q_len; i++){
		ctr++;
		arr[get_index(qstr[i])]++;
	}
	int s_len = s.length();
	int ss_len = s_len - q_len;
	int ind, ans=0;
	int arr1[62], ctr1;

	for(int i=0; i<=ss_len; i++){
		ctr1 = ctr;
		for(int l=0; l<62; l++){
			arr1[l] = arr[l];
		}
		for(int j=0; j<s_len-i;j++){
			ind = get_index(s[i+j]);
			if(arr1[ind] > 0){
				arr1[ind]--;
				ctr1--;
			}
			if(ctr1 == 0){
                // cout << endl <<  "i: " << i << " j: " << j << " ans+= " << (s_len-j-i) << endl;
				ans += (s_len-j-i);
				break;
			}
		}
	}
	cout << ans << endl;
	return(ans);
}

// Found a better algo, implement it
