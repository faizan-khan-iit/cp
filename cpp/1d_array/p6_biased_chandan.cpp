#include <iostream>
#include <stack>
using namespace std;

int find_biased_sum(int n);

int main(){
	int n;
	cin >> n;
	find_biased_sum(n);
	return 0;
}

// Use a stack to store only positive elements
// Pop when encountering a zero
int find_biased_sum(int n){
	int ans=0, k;
	stack<int> s;
	for(int i=0; i<n; i++){
		cin >> k;
		if(k==0 && !s.empty()){
			s.pop();
		}else{
			s.push(k);
		}
	}
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}

	cout << ans << endl;
	return(ans);
}
