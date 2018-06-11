/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-19 03:01:51
 * Problem   : 1129 - Consistency Checker
 * CPU       : 0.256
 * Memory    : 7628
**/
#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
#define csl ios_base::sync_with_stdio(false);
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
struct node {
    node *childs[11];
    bool isLeaf;
} *root;
struct node* newNode () {
    //cout<<"/1/";
    struct node* newnode = new node;
    newnode->isLeaf = false;
    repu(i,0,11,1) {
        newnode->childs[i] = NULL;
    }
    return newnode;
}
bool inserter (string s) {
    //cout<<"\nHere"<<s<<"\n";
    node* newnode = root;
    int len = s.size();
    bool newcreated = false;
    repu(i,0,len,1) {
        if (!(newnode->childs[s[i]-'0'])) {
            newnode->childs[s[i]-'0'] = newNode();
            newcreated = true;
        }
        newnode = newnode->childs[s[i]-'0'];
        if (newnode->isLeaf && !newcreated) return false;

    }
    newnode->isLeaf = true;
    if (!newcreated) return false;

    return true;
}
void clearall (struct node* root) {
	for (int i=0;i<11;i++) {
		if (root->childs[i]) {
			clearall(root->childs[i]);
			free(root->childs[i]);
		}
	}
	return ;
}
int main() {
    //csl;
    int t,n;
    cin>>t;
    for (int tc=1;tc<=t;tc++) {
        cin>>n;
        //cout<<n;
        root = newNode();
        bool checker = true;

        string s;
        //cout<<n;
        while (n--) {
            cin>>s;
            //cout<<"\n";
            if (checker)
            if (!inserter(s)) {
                checker = false;
            }
        }
        cout<<"Case "<<tc<<": ";
        if (!checker) cout<<"NO\n";
        else cout<<"YES\n";
        clearall(root);
        free(root);
    }
return 0;
}
