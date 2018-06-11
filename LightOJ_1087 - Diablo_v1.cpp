/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-04-22 11:45:26
 * Problem   : 1087 - Diablo
 * CPU       : 0.136
 * Memory    : 4424
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
	int cnt;
};
struct treenode tree[550000];
int n,a[100005+50005];
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.cnt = l.cnt + r.cnt;
	return res;
}
void build (int cn, int ss, int es) {
	if (ss > es) return ;
	if (ss==es) {
		if (ss < n) tree[cn].cnt = 1;
		else tree[cn].cnt = 0;
		return ;
	}
	int mid = (ss+es)/2;
	build (2*cn,ss,mid);
	build (2*cn+1,mid+1,es);
	tree[cn] = combine(tree[2*cn],tree[2*cn+1]);
	return ;
}
void update (int cn, int ss, int es, int pt) {
	if(ss>es) return ;
	if (ss==es) {
		tree[cn].cnt = 1;
		return ;
	}
	int mid = (ss+es)/2;
	if (pt <= mid) 
		update (2*cn,ss,mid,pt);
	else
		update (2*cn+1,mid+1,es,pt);
	tree[cn] = combine (tree[2*cn], tree[2*cn+1]);
	return ;
}
int query (int cn, int ss, int es, int pt) {
	if (ss==es) {
		tree[cn].cnt = 0;
		return a[ss];
	}
	int mid = (ss+es)/2,ans;
	if (pt <= tree[2*cn].cnt)
		ans = query (2*cn,ss,mid,pt);
	else
		ans = query (2*cn+1,mid+1,es,pt-tree[2*cn].cnt);
	tree[cn] = combine (tree[2*cn], tree[2*cn+1]);
	return ans;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,q;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi();
    	int orin = n;
    	q=readi();
    	memset(a,0,sizeof(a));
    	memset(tree,0,sizeof(tree));
    	rep(i,n) a[i]=readi();
    	build (1,0,orin+q-1);
    	char c;
    	int id;
    	printf("Case %d:\n",tc);
    	rep(i,q) {
    		scanf("%c",&c); id=readi();
    		if (c=='c') {
    			if (tree[1].cnt >= id)
    				printf("%d\n",query (1,0,orin+q-1,id));
    			else
    				printf ("none\n");
    		}
    		else {
    			update (1,0,orin+q-1,n);
    			a[n++] = id;
    		}
    	}
    }
    return 0;
}