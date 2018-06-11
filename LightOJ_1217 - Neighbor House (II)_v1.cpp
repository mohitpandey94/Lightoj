/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-06-04 23:27:24
 * Problem   : 1217 - Neighbor House (II)
 * CPU       : 0.000
 * Memory    : 1696
**/
#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pi(x) printf("%d", x);
#define gc getchar_unlocked
#define ll long long
#define ff first
#define ss second
using namespace std;
int readi() {int n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
ll readl() {ll n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
int n;
int ar[1001];
int dp[1001];
int recurse (int i, int cost, int n) {
	if (i >= n) {
		return cost;
	}
	if(dp[i] != -1) return cost+dp[i];
	int ans = 0;
	//if (!dp[(i-1+n)%n] && !dp[(i+1+n)%n]) {
	//	dp[i] = true;
		// cout<<i<<",";
		ans= max (ans, max(recurse(i+2,cost+ar[i],n), recurse(i+1,cost,n)));
	//	dp[i] = false;
	//}
	// else {
	// 	ans = max(ans, recurse(i+1,cost));
	// }
	// ans = max (ans, max(recurse(i+1,cost,false), recurse(i+2,cost+ar[i],(i==0?true:false))));

	return dp[i]=ans;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi();
    	
    	rep(i,n) {
    		ar[i] = readi();
    	}
    	memset(dp,-1,sizeof(dp));
    	int ans = 0;
    	ans = recurse(0,0,n-1);
    	// cout<<"\n";
    	memset(dp,-1,sizeof(dp));
    	ans = max(ans, recurse(1,0,n));
    	printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}