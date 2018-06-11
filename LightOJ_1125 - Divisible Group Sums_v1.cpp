/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-01-28 14:46:51
 * Problem   : 1125 - Divisible Group Sums
 * CPU       : 0.608
 * Memory    : 2436
**/
#include <bits/stdc++.h>
#define fu(i, a, n) for (ll i = a; i < n; i++)
#define fd(i, n, a) for (ll i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define sl(x) scanf("%lld", &x); //sl(x) is for long long ll.
#define si(x) scanf("%d", &x);
#define pl(x) prllf("%lld", x);  //pl(x) is for long long ll.
#define pln(x) prllf("%lld\n", x);  //..n(x) is for prlling with New Line.
#define ps(x) prllf("%lld ", x);  //..s(x) is for prlling with Space.
#define pi(x) prllf("%d", x);
#define pin(x) prllf("%d\n", x);
#define pis(x) prllf("%d ", x);
#define reset(x) memset(x,-1,sizeof(x))
#define gc getchar_unlocked
#define ll long long
using namespace std;
ll readi() {ll n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
ll readl() {ll n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
//
ll dp[211][22][12],d;
ll add (ll a, ll b) {
	ll sum = a+b;
	sum %= d;
	if (sum < 0) sum += d;
	return sum;
}
ll recurse (ll m,vector<ll> v, ll idx, ll sum) {
	if (idx == v.size() || m == 0) 
		return (m==0) && (sum%d==0);
	if (dp[idx][sum][m] != -1) 
		return dp[idx][sum][m];
	dp[idx][sum][m] =   recurse (m,v,idx+1,sum) + recurse (m-1,v,idx+1,add(sum,v[idx]));

	return dp[idx][sum][m];
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    ll t,q,n,m;
    t=readi();
    
    vector<ll> v;
    fu(tc,1,t+1) {
    	n=readi(), q=readi();
    	v.resize(n);
    	rep(i,n) {
    		//cin>>v[i];
    		v[i] = readi();
    	}
    	printf("Case %lld:\n",tc);
    	while (q--) {
    		d=readi(), m=readi();
    		//cin>>d>>m;
    		vector<ll> vv = v;
    		rep(i,n) {
    			vv[i] %= d;
    			if (vv[i] < 0) vv[i] += d;
    		}
    		reset(dp);
    		printf("%lld\n", recurse(m,vv,0,0));
    	}
    }
    return 0;
}