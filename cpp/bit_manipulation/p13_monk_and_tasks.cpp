/*
To test Monk A, Monk D provided him tasks for N days in the form of an array Array,
where the elements of the array represent the number of tasks.

The number of tasks performed by Monk A on the ith day is the number of ones in the
binary representation of Array_i.

Monk A is fed up of Monk D, so to irritate him even more, he decides to print the
tasks provided in non-decreasing order of the tasks performed by him on each day.
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long array_i[100000] = {0};
void print_tasks(int n);

int main(){
	int t=0; //test cases
	cin >> t;
	int n;
	for(int l=0; l<t; l++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> array_i[i];
		}
		print_tasks(n);
	}
	return 0;
}

void print_tasks(int n){
	std::vector<pair <int, long long> > ans;
	for(int i=0; i<n; i++){
		ans.push_back(make_pair(__builtin_popcount(array_i[i]), array_i[i]));
	}
	sort(ans.begin(), ans.end());
	for(int j=0; j<n-1; j++){
		cout << ans[j].second << " ";
	}
	cout << ans[n-1].second << endl;
	return;
}
