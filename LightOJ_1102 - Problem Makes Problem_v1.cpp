/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-24 03:04:24
 * Problem   : 1102 - Problem Makes Problem
 * CPU       : 0.068
 * Memory    : 17312
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
#define MAXN 2000000
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
ll fact[MAXN+1];
void pre() {
	fact[0] = 1;
	fu(i,1,MAXN+1) {
		fact[i] = (fact[i-1]*i)%MOD;
	}
}
ll powm (ll x, ll y) {
	ll res = 1LL;
	while (y > 0) {
		if (y&1) {
			res *= x;
		}
		x *= x;
		y /= 2;
		x %= MOD;
		res %= MOD;
	}
	return (res%MOD);
}
ll inv (ll x) {
	return powm(x, MOD-2);
} 
ll nCk (ll x, ll y) {
	return ((fact[x]*inv(fact[y]))%MOD*(inv(fact[x-y])))%MOD;
}
int main () {
	pre();
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t;
    ll n,k;
    t=readi();
    fu(tc,1,t+1) {
    	n=readl(), k = readl();
    	ll nn = n+k-1;
    	ll kk = n;
    	printf("Case %d: %lld\n",tc,nCk(nn,kk));
    }
    return 0;
}