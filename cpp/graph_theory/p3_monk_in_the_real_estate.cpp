/*
The Monk wants to buy some cities. To buy two cities, he needs to buy the road connecting
those two cities. Now, you are given a list of roads, bought by the Monk.
You need to tell how many cities did the Monk buy.
*/
#include <iostream>
using namespace std;


int arr_nodes[10001] = {0};
int sum(){
	int ans=0;
	for(int i=0;i<10001;i++){
		ans+=arr_nodes[i];
		arr_nodes[i] = 0;
	}
	return(ans);
}

int main(){
	int t; // test cases
	cin >> t;
	int e; // number of roads
	int from_city, to_city;
	for(int q=0; q<t; q++){
		cin >> e;
		for(int j=0; j<e; j++){
			cin >> from_city;
			cin >> to_city;
			arr_nodes[from_city] = 1;
			arr_nodes[to_city] = 1;
		}
		int ans = sum();
		cout << ans << endl;
	}
	return 0;
}
