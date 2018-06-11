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
    node *childs[11];
    bool isLeaf;
} *root;
struct node* newNode () {
    //cout<<"/1/";
    struct node* newnode = new node;
    newnode->isLeaf = false;
    rep(i,11) {
        newnode->childs[i] = NULL;
    }
    return newnode;
}
bool inserter (string s) {
    //cout<<"\nHere"<<s<<"\n";
    node* newnode = root;
    int len = s.size();
    bool newcreated = false;
    rep(i,len) {
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
