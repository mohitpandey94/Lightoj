/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-27 16:39:33
 * Problem   : 1028 - Trailing Zeroes (I)
 * CPU       : 0.640
 * Memory    : 13000
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
vector<ll> primes;
bool isprime[10000001];
	int k=0;
void seive () {
	isprime[0] = isprime[1] = 1;
	for (int i = 2; i <= 1000001; i++) {
		if (!isprime[i]) {
			primes.pb(i);
			for (int j = i+i; j <= 1000001; j += i) {
				isprime[j] = 1;
			}
		}
	}
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    seive();
    int t;
    ll n;
    t=readi();
    fu(tc,1,t+1) {
    	// n = readl();
    	cin>>n;
    	ll fexpo = 1;
    	ll expo = 0;
    	int rootn = sqrt(n);
    	/*for (int i=0; i < 10; i++) cout<<primes[i]<<" ";
    		cout<<"\n";*/
    	// cout<<n<<":\n";
    	for (int i=0; i < primes.size() && primes[i]*primes[i] <=n ; i++) {
    		while (n && (n%primes[i] == 0)) {
    			n /= primes[i];
    			expo++;
    		}
    		/*if (expo) {
    			// cout<<primes[i]<<" "<<expo<<"\n";
    		}*/
    		fexpo *= (expo+1);
    		expo= 0;
    	}

    	if (n > 1) {
    		fexpo *= 2;
    		//n /= n;
    	}
    	printf("Case %d: %lld\n",tc,fexpo-1);
    }
    return 0;
}