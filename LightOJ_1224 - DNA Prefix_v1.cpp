/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-19 03:43:36
 * Problem   : 1224 - DNA Prefix
 * CPU       : 0.744
 * Memory    : 48152
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
struct node {
	node* childs[4];
	bool isleaf;
	int count, len;
} *root;
struct node* newnode(int l) {
	struct node* temp = new node;
	temp->isleaf = false;
	for (int i=0;i<4;i++) temp->childs[i] = NULL;
	temp->count = temp->len = l;

	return temp;
}
int maxans;
void insert (string s) {
	struct node* temp = root;
	int sz = s.size();
	rep(i,sz) {
		int ind = (s[i]=='A' ? 0: (s[i]=='C'? 1: (s[i]=='G' ? 2 : (s[i]=='T' ? 3:0))));
		if (!(temp->childs[ind])) {
			int l = (i == sz-1 ? 0:i+1);
			temp->childs[ind] = newnode(l);
		}
		else if (i != sz-1) {
			// if (temp->childs[s[i]-'A']->isleaf) {
				temp->childs[ind]->count+=temp->childs[ind]->len;
				maxans = max (maxans, temp->childs[ind]->count);
			// }
		}
		temp = temp->childs[ind];
	}
	temp->isleaf = true;
	temp->len = sz;
	temp->count+=temp->len;
	maxans = max(maxans, temp->count);
	// delete (temp);
}
void clearall (struct node* root) {
	for (int i=0;i<4;i++) {
		if (root->childs[i]) {
			clearall(root->childs[i]);
			delete (root->childs[i]);
		}
	}
	return ;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n;
    t=readi();
    fu(tc,1,t+1) {
    	root = newnode(0);
    	n=readi();
    	maxans = -1;
    	string s;
    	rep(i,n) {
    		cin>>s;
    		insert(s);
    		// cout<<maxans<<" ";
    	}
    	printf("Case %d: %d\n",tc,maxans);
    	clearall(root);
    	delete (root);
    }
    return 0;
}