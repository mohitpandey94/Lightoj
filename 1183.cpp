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
#define MAXN 100000
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
	ll size, sum;
	treenode () {
		size=0,sum=0;
	}
};
struct treenode tree[4*MAXN];
ll lazy[4*MAXN];
bool islazy[4*MAXN];
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.sum = l.sum + r.sum;
	res.size = l.size + r.size;
	return res;
}
struct treenode makenode (int val) {
	struct treenode res;
	res.sum = val;
	res.size = 1;
	return res;
}
void build (int cn, int ss, int es) {
	if (ss > es) return ;
	if (ss == es) {
		tree[cn] = makenode(0);
		return ;
	}
	build(2*cn,ss,(ss+es)/2);
	build(2*cn+1,(ss+es)/2+1,es);
	tree[cn] = combine(tree[cn*2], tree[cn*2+1]);
}
struct treenode nullnode;
void update (int cn, int ss, int es, int i, int j, ll val)  {
	if (islazy[cn]) {
		if (ss == es) {
			tree[cn].sum = lazy[cn];
		}
		else {
			tree[cn].sum = lazy[cn]*(es-ss+1);
			lazy[2*cn] = lazy[cn];
			lazy[2*cn+1] = lazy[cn];
			islazy[cn*2]=islazy[cn*2+1]=true;
		}
		lazy[cn] = 0;
		islazy[cn]=false;
	}
	if (ss > es || i > es || j < ss) return ;
	if (ss >= i &&  es <= j) {
		if (ss == es) {
			tree[cn].sum = val;
		}
		else {
			tree[cn].sum = val*(es-ss+1);
			lazy[cn*2] = val;
			lazy[cn*2+1] = val;
			islazy[cn*2]=islazy[cn*2+1]=true;
		}
		return ;
	}
	update (2*cn,ss,(es+ss)/2,i,j,val);
	update (2*cn+1,(ss+es)/2+1,es,i,j,val);
	tree[cn].sum = tree[cn*2].sum + tree[cn*2+1].sum;
}
struct treenode query (int cn, int ss, int es, int i, int j) {
	if (ss > es || i > es || j < ss) return nullnode;
	if (islazy[cn]) {
		if (ss==es){
			tree[cn].sum = lazy[cn];
		}
		else {
			tree[cn].sum = lazy[cn]*(es-ss+1);
			lazy[cn*2] = lazy[cn];
			lazy[cn*2+1] = lazy[cn];
			islazy[cn*2]=islazy[cn*2+1]=true;
		}
		lazy[cn] = 0;
		islazy[cn]=false;
	}
	if (ss >= i && es <= j) {
		return tree[cn];
	}
	treenode l = query (2*cn, ss, (ss+es)/2, i, j);
	treenode r = query (2*cn+1, (ss+es)/2+1, es, i, j);
	treenode res = combine(l,r);
	return res;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    nullnode.size=nullnode.sum=0;
    ll t,n,q,x,y,z,type;
    t=readl();
    fu(tc,1,t+1) {
    	rep(i,4*MAXN+1) {
    		tree[i].sum = tree[i].size= 0;
    		lazy[i]=0;
    		islazy[i]=false;
    	} 
    	n=readl(), q=readl();
    	build (1,0,n-1);
    	printf("Case %d:\n",tc);
    	while (q--) {
    		type =readl();
    		if (type==2) {
    			x=readl(), y=readl();
    			struct treenode ans = query (1,0,n-1,x,y);
    			// printf ("::%lld ", ans.sum);
    			// printf ("%lld\n", ans.size);
    			int deno = __gcd (ans.size, ans.sum);
    			ans.size /= deno;
    			ans.sum /= deno;
    			if (ans.size > 1)
    				printf("%lld/%lld\n",ans.sum, ans.size);
    			else
    				printf ("%lld\n", ans.sum);
    				

    		}
    		else {
    			x=readl(), y=readl(), z=readl();
    			update (1,0,n-1,x,y,z);
    		}
    	}
    }
    return 0;
}