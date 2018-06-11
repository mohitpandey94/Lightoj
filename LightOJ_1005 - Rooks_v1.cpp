/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-15 05:07:53
 * Problem   : 1005 - Rooks
 * CPU       : 0.008
 * Memory    : 1696
**/
#include <bits/stdc++.h>
#define un unsigned
using namespace std;
un long long memo[32][32];
int turn = 0;
un long long fact[32];
void pre() {
	fact[0] = 1;
	for (int i=1; i<32; i++) {
		fact[i] = fact[i-1]*i;
		if (fact[i] < 0) {
			cout<<i<<"<-";
			break;
		}
	} 
}
un long long call (un long long n, un long long k) {
	//cout<<turn<<"  "<<n<<" "<<k<<"\n";
	if (k > n) return 0;
	if (k == 0 || n == k) {
		memo[n][k] =  1;
		return memo[n][k];
		//return 1;
	}
	if (memo[n][k] != 0) return memo[n][k];
	memo[n][k] = (n*(call(n-1, k-1)))/k;
	//memo[n][k] = ans;
	return memo[n][k];
}
int main() {
	pre();
	un long long n=4, k=3;
	memset(memo, 0, sizeof memo);
	int t;
	cin>>t;
	for (int tc=1; tc<=t; tc++) {
		cin>>n>>k;
		un long long ans = call(n,k);
		//cout<<ans<<" ";
		ans = ans*ans;
		//cout<<ans<<" ";
		ans = ans * fact[k];
		printf("Case %d: %llu\n", tc, ans);
	}
}