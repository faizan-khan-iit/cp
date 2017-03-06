#include <iostream>
#include <queue>
using namespace std;

int calling_arr[100];
int ideal_arr[100];
int find_time(int n);

int main(){
	int n;
	cin >> n;
	find_time(n);
	return 0;
}

int find_time(int n){
	queue <int> calling_q;
	int k, time=0;

	// Use a queue for calling order
	for(int i=0; i<n; i++){
		cin >> k;
		calling_q.push(k);
	}
	for(int i=0; i<n; i++){
		cin >> ideal_arr[i];
	}

	// Keep checking if element is same as ideal order
	// If not, push to last place
	for(int i=0; i<n; i++){
		k = calling_q.front();
		while(k != ideal_arr[i]){
			calling_q.pop();
			calling_q.push(k);
			time++;
			k = calling_q.front();
		}
		// We remove this from the calling order
		calling_q.pop();
		time++;
	}
	cout << time << endl;
	return(time);
}
