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
	node* bit[2];
} *root;
struct node* newnode() {
	struct node* temp = new node;
	temp->bit[0]=temp->bit[1] = NULL;
	return temp;
}
void insert (int bits[]) {
	struct node* temp = root;
	fd(i,31,0) {
		// cout<<bits[i]<<" ";
		if (!(temp->bit[bits[i]])) {
			temp->bit[bits[i]] = newnode();
		}
		temp = temp->bit[bits[i]];
	}
}
int maxx (int bits[]) {
	struct node* temp = root;
	int sum = 0;
	fd(i,31,0) {
		// cout<<bits[i]<<" ";
		if (!(temp->bit[(bits[i]+1)%2])) {
			temp = temp->bit[bits[i]];
			sum *= 2;
			sum += 0;
		}
		else {
			temp = temp->bit[(bits[i]+1)%2];
			sum *= 2;
			sum += 1;
		}
	}
	// cout<<"\n";
	return sum;
}
int minn (int bits[]) {
	struct node* temp = root;
	int sum = 0;
	fd(i,31,0) {
		// cout<<bits[i]<<" ";
		if (!(temp->bit[bits[i]])) {
			temp = temp->bit[(bits[i]+1)%2];
			sum *= 2;
			sum += 1;
		}
		else {
			temp = temp->bit[bits[i]];
			sum *= 2;
			sum += 0;
		}
	}
	// cout<<"\n";
	return sum;
}

void clearall (struct node* root) {
	for (int i=0;i<2;i++) {
		if (root->bit[i]) {
			clearall(root->bit[i]);
			free(root->bit[i]);
		}
	}
	return ;
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,x;
    t=readi();
    fu(tc,1,t+1) {
    	n=readi();
    	root = newnode();
    	int a[50001],bits[32];
    	rep(i,n) {
    		a[i]=readi();
    		if(i>1) a[i] ^= a[i-1];
    	}
    	memset(bits,0,sizeof(bits));
    	insert(bits);
    	int maxi = -1,mini = INT_MAX;
    	// cout<<mini<<"::";
    	rep(i,n) {
    		memset(bits,0,sizeof(bits));
    		int temp = a[i],k=0;
    		while (temp) {
    			bits[k++] = temp%2;
    			temp /= 2;
    		}
    		maxi = max (maxi, maxx(bits));
    		mini = min (mini, minn(bits));
    		// cout<<maxi<<" "<<mini<<",";
    		insert(bits);
    	}
    	printf("Case %d: %d %d\n",tc,maxi,mini);
    	clearall(root);
    	delete (root);
    }
    return 0;
}