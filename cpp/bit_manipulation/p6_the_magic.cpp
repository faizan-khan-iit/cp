/*
Navi got a task at school to collect N stones. Each day he can collect only
one stone. As N can be a very large number so it could take many days to complete
the task, but then he remembers that his mother gave him a magic that can double
anything (i.e if he has 2 stones, the magic will make them to 4 stones).
Navi can use this magic any number of time on the collected stone on a particular
day and add this to the previously collected stones. Remember that he wants 
exactly N stones and he can't throw any stone. If he gets more than N stones
then he gets 0 marks, of course he doesn't want 0 marks. Help him to collect
exactly N stones in minimum number of days.
*/
#include <iostream>
using namespace std;

long long find_days(long long n);

int main(){
	int t=0; //test cases
	cin >> t;
	long long n = 0;
	for(int l=0; l<t; l++){
		cin >> n;
		find_days(n);
	}
	return 0;
}

// Count number of 1's in binary represenation
// For 21 = 16 + 4 + 1
// 21 = 10101 => ans = 3
long long find_days(long long n){
	long long ans = 0;
	while(n){
		// If last bit is 1
		if((n&1) != 0){
			ans++;
		}
		n = n >> 1; // Divide by two
	}
	cout << ans << endl;
	return(ans);
}
