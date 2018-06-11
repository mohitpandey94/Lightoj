/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-06-05 19:58:46
 * Problem   : 1169 - Monkeys on Twin Tower
 * CPU       : 0.004
 * Memory    : 1712
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
int a[2][1001];
int t[2][1001];
int ans1[1001],ans2[1001];
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int tt,n;
    tt=readi();
    fu(tc,1,tt+1) {
    	n=readi();
    	memset(a,0,sizeof(a));
    	memset(t,0,sizeof(t));
    	memset(ans1,0,sizeof(ans1));
    	memset(ans2,0,sizeof(ans2));

    	rep(i,n) {
    		a[0][i] = readi();
    	}
    	rep(i,n) {
    		a[1][i] = readi();
    	}
    	rep(i,n-1) {
    		t[0][i] = readi();
    	}
    	rep(i,n-1) {
    		t[1][i] = readi();
    	}
    	ans1[0] = a[0][0]; ans2[0] = a[1][0];
    	for (int i=1; i < n; i++) {
    		ans1[i] = min (ans1[i-1]+a[0][i], ans2[i-1]+ a[0][i] + t[1][i-1]);
    		ans2[i] = min (ans2[i-1]+a[1][i], ans1[i-1]+ a[1][i] + t[0][i-1]);
    	}
    	printf("Case %d: %d\n",tc,min(ans1[n-1],ans2[n-1]));
    }
    return 0;
}