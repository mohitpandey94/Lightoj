/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2018-04-20 00:14:00
 * Problem   : 1104 - Birthday Paradox
 * CPU       : 1.068
 * Memory    : 1684
**/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int tc=1; tc<=t; tc++) {
		int n;
		cin>>n;
		double prob = 1.0;
		int x = 1;
		for (x = 1; prob > 0.5; x++) {
			prob *= ((double)((n-x)*1.0)/n);
		}
		cout<<"Case "<<tc<<": "<<x-1<<endl;
	}
	return 0;
}