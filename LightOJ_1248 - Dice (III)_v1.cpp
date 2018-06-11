/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2018-04-20 00:28:36
 * Problem   : 1248 - Dice (III)
 * CPU       : 0.056
 * Memory    : 1684
**/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int t;
	cin>>t;
	cout<<std::fixed<<setprecision(7);
	for (int tc=1; tc<=t; tc++) {
		int n;
		cin>>n;
		double prob = 0.0;
		int x = 1;
		for (x = 1; x <= n; x++) {
			prob += (1.0/(double)(x*1.0));	
		}
		cout<<"Case "<<tc<<": "<<(prob*n*1.0)<<endl;
	}
	return 0;
}