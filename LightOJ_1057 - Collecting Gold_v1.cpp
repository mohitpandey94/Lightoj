/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-02-06 23:14:13
 * Problem   : 1057 - Collecting Gold
 * CPU       : 0.260
 * Memory    : 5784
**/
#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pln(x) printf("%lld\n", x);  //..n(x) is for printing with New Line.
#define ps(x) printf("%lld ", x);  //..s(x) is for printing with Space.
#define pi(x) printf("%d", x);
#define pin(x) printf("%d\n", x);
#define pis(x) printf("%d ", x);
#define gc getchar_unlocked
#define ll long long
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
pii golds[16];
int memo[16][1<<16];
int cnt;
int dist (pii x, pii y) {
	return max(abs(x.first-y.first), abs(x.second-y.second));
}
int rec (int ind, int mask) {
	if (mask == (1<<cnt)-1) return dist(golds[0], golds[ind]);
	if (memo[ind][mask] != -1) return memo[ind][mask];
	int ans = 99999;
	for (int i=0; i< cnt; i++) {
		if (!(mask & (1<<i))) {
			ans = min (ans, rec(i,mask|1<<i)+dist(golds[ind],golds[i]));
		}
	}
	return (memo[ind][mask]=ans);
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,m;
    cin>>t;
    fu(tc,1,t+1) {
    	cin>>n>>m;
    	char c;
    	cnt=1;
    	for (int i=0; i < n; i++) {
    		for (int j=0; j < m; j++) {
    			cin>>c;
    			if (c == '.') continue;
    			if (c=='g') {
    				golds[cnt++] = pii(i,j);
    			}
    			if (c=='x') golds[0] = pii(i,j);
    		}
    	}
    	memset(memo,-1,sizeof(memo));
    	printf ("Case %d: %d\n",tc,rec(0,1));
    }
    return 0;
}