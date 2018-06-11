/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-23 03:56:52
 * Problem   : 1161 - Extreme GCD
 * CPU       : 0.052
 * Memory    : 1844
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
ll cnt[10005], ans[10005];
ll nC4 (ll x) {
	x = (x*(x-1)*(x-2)*(x-3))/24;
	return x;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n;
    ll x;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi();
    	ll maxx = -1;
    	rep(i,n) {
    		x = readi();
    		maxx = max (maxx,x);
    		for (int j=1; j*j <= x; j++) {
    			if(x%j != 0) continue;
    			cnt[j]++;
    			if (j*j != x) {
    				cnt[x/j]++;
    			}
    		}
    	}
    	for (int i=maxx; i >= 1; i--) {
    		ans[i] = nC4(cnt[i]);
    		for (int j=i+i; j <= maxx; j += i) {
    			ans[i] -= ans[j];
    		}
    	}
    	printf("Case %d: %lld\n",tc,ans[1]);
    	memset(cnt,0,sizeof(cnt));
    }
    return 0;
}