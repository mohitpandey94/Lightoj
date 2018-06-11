/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-04-21 22:19:17
 * Problem   : 1093 - Ghajini
 * CPU       : 0.180
 * Memory    : 5204
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
	int maxi,mini;
};
struct treenode tree[4*100005], nullnode;
int a[100005];
struct treenode makenode (int mini, int maxi) {
	struct treenode res;
	res.mini =mini; res.maxi = maxi;
	return res;
}
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.mini = min(l.mini, r.mini);
	res.maxi = max(l.maxi, r.maxi);
	return res;
}
void build (int cn, int ss, int es) {
	if (ss > es) return ;
	if (ss==es) {
		tree[cn] = makenode(a[ss],a[ss]);
		return ;
	}
	int mid = (ss+es)/2;
	build (2*cn,ss,mid);
	build (2*cn+1,mid+1,es);
	tree[cn] = combine(tree[2*cn], tree[2*cn+1]);
}
struct treenode query (int cn, int ss, int es, int i, int j) {
	if (ss > es || j < ss || i > es) return nullnode;
	if (ss>=i && j>=es) {
		return tree[cn];
	}
	int mid = (ss+es)/2;
	struct treenode l = query (2*cn,ss,mid,i,j);
	struct treenode r = query (2*cn+1,mid+1,es,i,j);
	return combine (l, r);
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    nullnode.mini = INT_MAX;
    nullnode.maxi = INT_MIN;
    int t,n,d;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi(), d=readi();
    	// memset(tree,0,sizeof(tree));
    	memset(a,0,sizeof(a));
    	rep(i,n) {
    		a[i]=readi();
    	}
    	build (1,0,n-1);
    	// cout<<tree[1].mini<<" "<<tree[1].maxi<<"\n";/
    	// return 0;
    	struct treenode ans;
    	int fans = -1;
     	for (int i=0; i < n; i++) {
    		ans = query (1,0,n-1,i,i+d-1);
    		fans = max (fans, ans.maxi-ans.mini);
    		// cout<<i<<" "<<i+d-1<<" "<<" "<<ans.maxi<<" "<<ans.mini<<" "<<fans<<"\n";
    	}
    	printf ("Case %d: %d\n",tc,fans);
    }
    return 0;
}