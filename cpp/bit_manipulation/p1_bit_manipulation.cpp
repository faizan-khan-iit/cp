#include <iostream>
using namespace std;

int count_ones(int n);

int main(){
    int n=0;
    cout << "Enter the number in decimal format:" << endl;
    cin >> n;
    cout << "The number of ones is: " << count_ones(n) << endl;
    cout << __builtin_popcount(n); //inbuilt method gcc
	return 0;
}

// Count number of ones using bit manipulation
// Handles negatives too
int count_ones(int n){
    int count_1 = 0;
    while(n){
        // Set the last set bit (the last 1) as 0 every time until number is zero;
        n = n & (n-1);
        count_1++;
    }
    return(count_1);
}
