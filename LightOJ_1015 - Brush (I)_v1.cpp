/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-02-03 02:24:05
 * Problem   : 1015 - Brush (I)
 * CPU       : 0.024
 * Memory    : 1684
**/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	for (int tc=1;tc<=t;tc++) {
		cin>>n;
		int x;
		long long sum=0;
		for (int i=0;i<n;i++) cin>>x,sum += (x>=0?x:0);
		cout<<"Case "<<tc<<": "<<sum<<"\n";
	}
	return 0;
}