#include <iostream>
#include <stack>
using namespace std;

int is_bubbly(string word);

int main(){
	int m;
	cin >> m;
	int ans = 0;
	string word;
	for(int i=0; i<m; i++){
		cin >> word;
		ans += is_bubbly(word);
	}
	cout << ans << endl;
	return 0;
}

int is_bubbly(string word){
	int w_len = word.length();
	if((w_len%2)!=0){
		return(0);
	}
	stack <char> s;
	for(int i=0; i<w_len; i++){
		if(s.empty()){
			s.push(word[i]);
		}else if(s.top() == word[i]){
			s.pop();
		}
	}
	if(!s.empty()){
		return(0);
	}
	return(1);
}
