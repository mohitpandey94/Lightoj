/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-04-14 16:59:55
 * Problem   : 1082 - Array Queries
 * CPU       : 0.216
 * Memory    : 3640
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
struct treenode {
	int val;
};
struct treenode tree[4*100000];
int a[100000];
int combine (int cn) {
	return min (tree[2*cn].val, tree[2*cn+1].val);
}
void build (int ss, int es, int cn) {
	if (ss > es) return ;
	if (ss == es) {
	// cout<<ss<<" "<<es<<" "<<cn<<" "<<a[ss]<<"\n";
		tree[cn].val = a[ss];
		return ;
	}
	build (ss,(es+ss)/2,2*cn);
	build ((ss+es)/2+1,es,2*cn+1);
	tree[cn].val = combine (cn);
	return ;
}
int query (int ss, int es, int qs, int qe, int cn) {
	if (ss > es || ss > qe || es < qs) return -1;
	
	if (qs <= ss && es <= qe) {
		// cout<<ss<<" "<<es<<" "<<tree[cn].val<<"\n";
		return tree[cn].val;
	}
	int l = query(ss,(ss+es)/2,qs,qe,2*cn);
	int r = query((ss+es)/2+1,es,qs,qe,2*cn+1);

	// cout<<cn<<" "<<":"<<l<<" "<<r<<"\n";
	if (l==-1) return r;
	else if (r==-1) return l;
	else return min(l,r);
	// return combine(cn);
}
void print(struct treenode tree[], int n) {
	cout<<"\n";
	for (int cn=1; cn<=n-1;cn++) {
		cout<<tree[cn].val<<" "<<tree[2*cn].val<<" "<<tree[2*cn+1].val<<"\n";
	}
	cout<<"\n";
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,q,qs,qe;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi(), q=readi();
    	rep(i,n) {
    		a[i]=readi();
    	}
    	build (0,n-1,1);
    	printf("Case %d:\n",tc);
    	// print(tree,n);
    	// cout<<tree[0].val<<" "<<tree[3].val<<"\n";
    	while (q--) {
    		qs=readi(), qe=readi();
    		qs--,qe--;
    		printf("%d\n",query(0,n-1,qs,qe,1));
    	}
    	memset(tree,0,sizeof(tree));
    	memset(a,0,sizeof(a));
    }
    return 0;
}