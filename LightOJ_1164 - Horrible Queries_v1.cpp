/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-04-16 13:35:31
 * Problem   : 1164 - Horrible Queries
 * CPU       : 0.268
 * Memory    : 7940
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
#define MAXN 100000
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
struct treenode {
	ll val;
};
struct treenode tree[MAXN*4];
ll lazy[MAXN*4];
void update (int cn, int ss, int es, int us, int ue, ll val) {
	if (lazy[cn]) {
		if (ss==es){
			tree[cn].val += lazy[cn];
		}
		else {
			tree[cn].val += lazy[cn]*(es-ss+1);
			lazy[cn*2] += lazy[cn];
			lazy[cn*2+1] += lazy[cn];
		}
		lazy[cn] = 0;
	}
	if (ss > es || us > es || ss > ue) return ;
	if (ss >= us && es <= ue) {
		if (ss==es) {
			tree[cn].val += val;
		}
		else {
			tree[cn].val += val*(es-ss+1);
			lazy[cn*2]  += val;
			lazy[cn*2+1]  += val;
		}
		return ;
	}
	update (2*cn, ss, (ss+es)/2, us, ue, val);
	update (2*cn+1, (ss+es)/2+1,es,us,ue,val);
	tree[cn].val = tree[2*cn].val+tree[2*cn+1].val;
}
ll query (int cn, int ss, int es, int qs, int qe) {
	if (ss > es || qs > es || ss > qe) return 0;
	if (lazy[cn]) {
		if (ss==es){
			tree[cn].val += lazy[cn];
		}
		else {
			tree[cn].val += lazy[cn]*(es-ss+1);
			lazy[cn*2] += lazy[cn];
			lazy[cn*2+1] += lazy[cn];
		}
		lazy[cn] = 0;
	}
	if (ss >= qs && es <= qe) {
		return tree[cn].val;
	}
	ll l = query (2*cn, ss, (ss+es)/2, qs, qe);
	ll r = query (2*cn+1, (ss+es)/2+1, es, qs, qe);
	return (l+r);
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    ll t,n,q,type,x,y,z;
    t=readl();
    fu(tc,1,t+1) {
    	n=readl(), q=readl();
    	rep(i,4*MAXN+1) {
    		tree[i].val = lazy[i] = 0;
    	}
    	printf("Case %d:\n", tc);
    	while (q--) {	
    		type=readl();
    		if (type) {
    			x=readl(), y=readl();
    			//x--; y--;
    			printf("%lld\n", query(1,0,n-1,x,y));
    		}
    		else {
    			x=readl(), y=readl(), z=readl();
    			//x--; y--;
    			update(1,0,n-1,x,y,z);
    		}
    	}	
    }
    return 0;
}