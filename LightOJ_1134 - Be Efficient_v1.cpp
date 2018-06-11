/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-02-07 05:29:50
 * Problem   : 1134 - Be Efficient
 * CPU       : 0.292
 * Memory    : 3964
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
ll count (ll x) {
	if (x<0) return 0;
	return ((x*(x+1))/2);
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,m;
    ll ans;
    vector<ll> v,freq;
    cin>>t;
    fu(tc,1,t+1) {
    	cin>>n>>m;
    	v.resize(n); freq.resize(m);
    	rep(i,n) {
    		cin>>v[i];
    	}
    	v[0] %= m;
    	//cout<<v[0]<<" ";
    	freq[v[0]]++;
    	fu(i,1,n) {
    		v[i] = (v[i]+v[i-1])%m;
    		//cout<<v[i]<<" ";
    		freq[v[i]]++;
    	}
    	//cout<<"\n";
    	ans=0;
    	ans = freq[0];
    	for (int i=0; i< m; i++) {
    		ans += count(freq[i]-1);
    		//cout<<i<<" "<<freq[i]<<" "<<ans<<",";
    	}
    	printf ("Case %d: %lld\n",tc,ans);
    	v.clear(), freq.clear();
    }
    return 0;
}