/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2018-04-15 17:36:06
 * Problem   : 1030 - Discovering Gold
 * CPU       : 0.012
 * Memory    : 1688
**/
#include <bits/stdc++.h>
using namespace std;
int n;
double gold[101];
double memo[101];
double recurse(int x) {
	
	if (x == n) {
		memo[n] = gold[n];
		return memo[n];
	}
	if (memo[x] != 0) return memo[x];
	
	if (n - x <= 5) {
		for (int i = n; i > x; i--) {
			memo[x] += recurse(i)*1.0;
		}
		
		memo[x] /= (n-x);
		//cout<<x<<","<<memo[x]<<","<<gold[x]<<endl;
		return memo[x]+=gold[x];
	}
	else {
		for (int i=x+6; i > x; i--) {
			memo[x] += recurse(i);
		}
		memo[x] /= 6.0;
		return memo[x]+=gold[x];
	}
}
int main() {
	int t;
	cin>>t;
	for (int tc=1; tc<=t; tc++) {
		cin>>n;
		//cout<<tc<<","<<t<<","<<n<<endl;
		memset(memo, 0, sizeof(memo));
		
		gold[0] = 0;
		for (int i=1; i <= n; i++) {
			cin>>gold[i];
			//cout<<gold[i]<<"\n";
		}
		
		printf("Case %d: %0.8f\n",tc,recurse(1));
		//for (int i=1; i <= n; i++) cout<<memo[i]<<endl;
	}
	
	return 0;
}