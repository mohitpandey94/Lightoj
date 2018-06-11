/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-02-06 12:30:16
 * Problem   : 1018 - Brush (IV)
 * CPU       : 0.308
 * Memory    : 2200
**/
#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pln(x) printf("%lld\n", x);  //..n(x) is for printing with New Line.
#define ps(x) printf("%lld ", x);  //..s(x) is for printing with Space.
#define pi(x) printf("%d", x);
#define pin(x) printf("%d\n", x);
#define pis(x) printf("%d ", x);
#define gc getchar_unlocked
#define pii pair<int,int> 
#define ff first
#define ss second
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
vector <pii> v;
int counter[17][17],n;
bool sameline (int i, int j, int k) {
	return ((v[i].ff*(v[j].ss-v[k].ss)+v[j].ff*(v[k].ss-v[i].ss)+v[k].ff*(v[i].ss-v[j].ss))==0);
}
void pre(int n) {
	rep(i,n) {
		rep(j,n) {
			if (i != j) {
				rep(k,n) { 
					if (sameline(i,j,k))
						counter[i][j] |= 1<<k;
				}
			}
		}
	}
	return ;
}
int memo[1<<17];
int rec (int mask) {
	//cout<<mask<<" ";
	if (mask == (1<<n)-1) {
		return 0;
	}
	if (memo[mask] != -1) 
		return memo[mask];
	if (__builtin_popcount(mask) == n-1)
		return memo[mask] = 1;
	int i,best = 20;
	for (i=0;i < n && (mask & (1<<i)); i++);  
		for (int j=0; j<n; j++) {
			if (i !=j && !(mask & (1<<j))) {
				best = min (best, rec(mask|counter[i][j])+1);
			}
		}
	
	return (memo[mask] = best);
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t;
    cin>>t;
    fu(tc,1,t+1) {
    	cin>>n;
    	v.resize(n);
    	rep(i,n) {
    		cin>>v[i].ff>>v[i].ss;
    	}
    	memset (counter,0,sizeof(counter));
    	pre(n);
    	/*
    	rep(i,n) {
    		rep (j,n) {
    			if (i != j)
    				cout<<counter[i][j]<<" ";
    		}
    		cout<<"\n";
    	}
    	*/
    	memset(memo,-1,sizeof(memo));
    	printf ("Case %d: %d\n",tc,rec(0));
    }
    return 0;
}