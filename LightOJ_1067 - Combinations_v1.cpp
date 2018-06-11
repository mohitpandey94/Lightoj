/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-23 08:18:56
 * Problem   : 1067 - Combinations
 * CPU       : 0.024
 * Memory    : 9500
**/
#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000003
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
ll fact[1000002];
void pre() {
	fact[0] = 1;
	fu(i,1,1000002) {
		fact[i] = fact[i-1]*i;
		if (fact[i] > MOD) fact[i] %= MOD;
	}
}
ll power (ll x, ll y) {
	ll res = 1LL;
	while (y > 0) {
		if (y&1) {
			res = res*x;
			res %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return res%MOD;
}
ll inv (ll x) {
	return power(x,MOD-2);
}
ll nCk (ll n, ll k) {
	return (((fact[n]*inv(fact[n-k]))%MOD)*inv(fact[k]))%MOD;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    pre();
    int t;
    ll n,k;
    t=readi();
    fu(tc,1,t+1) {
    	n=readl(), k = readl();
    	printf("Case %d: %lld\n",tc,nCk(n,k));
    }
    return 0;
}