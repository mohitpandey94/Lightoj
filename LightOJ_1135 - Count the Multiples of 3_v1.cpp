/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-09-26 22:17:52
 * Problem   : 1135 - Count the Multiples of 3
 * CPU       : 0.320
 * Memory    : 7940
**/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector < vector<int> > vvi;
typedef vector < vector<ll> > vvl;
 
#define sl(x) scanf("%lld", &x) //s(x) is for long long int.
#define si(x) scanf("%d", &x)
 
#define debug true
#define ok if(debug)
#define trace(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "  << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define rep(i, a, b) \
		for (int i = int(a); i <= int(b); i++)
#define nrep(i,a,b) \
		for (int i = int(a); i >= int(b); i--)
#define trv(it, c) \
		for (auto it = (c).begin(); it != (c).end(); it++)
#define mkp make_pair
#define pb push_back
#define X first
#define Y second
 
#define MOD 1000000007 //10^9 + 7
#define MAXN 100005
struct treenode {
	// int val; 
	int c0,c1,c2, added;
	treenode () {
		c0 = 1; c1=c2=added=0;
	}
};
struct treenode tree[4*MAXN];

struct treenode makenode() {
	struct treenode temp;
	// temp.val =0; 
	temp.c0 = 1; temp.c1=temp.c2=temp.added=0;
	return temp;
}
struct treenode combine (struct treenode l, struct treenode r) {
	struct treenode res;
	res.c0 = l.c0 + r.c0;
	res.c1 = l.c1 + r.c1;
	res.c2 = l.c2 + r.c2;
	return res;
}
void build (int cn, int ss, int es) {
	if (ss>es) {
		return;
	}
	if (ss == es) {
		tree[cn] = makenode();
		return ;
	}
	int mid = (ss+es)/2;
	build(2*cn, ss, mid);
	build(2*cn+1, mid+1, es);
	tree[cn] = combine(tree[2*cn], tree[2*cn+1]);
}
struct treenode update_node (struct treenode x) {
	int temp = x.c0;
	x.c0 = x.c2;
	x.c2 = x.c1;
	x.c1 = temp;
	return x;
}
void childs (int cn) {
	if (tree[cn].added == 0) return ;
	tree[cn].added %= 3;
	tree[2*cn].added += tree[cn].added;
	tree[2*cn+1].added += tree[cn].added;
	for (int i=0; i < tree[cn].added; i++) {
		tree[2*cn] = update_node(tree[2*cn]);
		tree[2*cn+1] = update_node(tree[2*cn+1]);
	}
	tree[cn].added = 0;
	return ;
}
void update (int cn, int ss, int es, int i, int j, int val) {
	if (i > es or j < ss) return;
	if (ss>=i and es <= j) {
		tree[cn].added++;
		tree[cn] = update_node(tree[cn]);
		return ;
	}
	childs(cn);
	int mid = (ss+es)/2;
	if (i <= mid) update(2*cn, ss, mid, i, j, val);
	if (j > mid) update(2*cn+1, mid+1, es, i, j, val);
	tree[cn] = combine(tree[2*cn], tree[2*cn+1]);
}
int query (int cn, int ss, int es, int i, int j) {
	if (ss>=i and es <= j) {
		return tree[cn].c0;
	}
	childs(cn);
	int mid = (ss+es)/2, ans = 0;
	if (i <= mid) ans += query (2*cn, ss, mid, i, j);
	if (j > mid) ans += query (2*cn+1, mid+1, es, i, j);
	return ans;
}
void printtree (int n) {
	for (int i=0; 2*i+1 < n; i++) {
		cout<<tree[i].added<<" "<<tree[2*i].added<<" "<<tree[2*i+1].added<<endl;
	}

}
int main() {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
	int t,n,q;
	si(t);
	rep(tc,1,t) {
		si(n), si(q);
		// memset(tree, 0, sizeof(tree));
		build(1,1,n);
		int type,x,y;

		printf("Case %d:\n",tc);
		for (int i=0; i < q; i++) {
			si(type), si(x), si(y);
			if (type == 0) {
				update(1, 1, n, x+1, y+1, 1);
				// printtree(n);
			}
			if(type==1) {
				printf("%d\n", query(1, 1, n, x+1, y+1));
			}
			// cout<<endl;
		}
	}
	return 0;
}