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
ll n,m,ans;
ll a[16], inset[16],prod,gcd;
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t;
    t=readi();
    fu(tc,1,t+1) {
    	n=readl(), m = readl();
    	ans=n;
    	rep(i,m) {
    		a[i] = readl();
    		ans -= (n/a[i]);
    	}
    	cout<<ans<<"::::\n";
    	for (int i=1; i < (1<<m); i++) {
    		int k=0;
    		for (int j=0; (1<<j) <= i; j++) {
    			if (i & (1<<j)) {
    				inset[k++] = j;
    			}
    		}
    		if(k == 1) continue;
    		gcd = a[inset[0]];
    		prod = 1LL;
    		cout<<"set:";
    		for (int j=0;j<k;j++) {
    			gcd = __gcd(gcd, a[inset[j]]);
    			cout<<a[inset[j]]<<" ";
    		}
    		cout<<"\n";
    		bool flag = true;
    		for (int j=0;j<k;j++) {
    			prod = prod * a[inset[j]];
    		}
    		prod /= gcd;
    		cout<<gcd<<" "<<prod<<"\n";
    		ans += (n/prod)*(k-1);
    		cout<<ans<<"\n";
    	}
    	printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}