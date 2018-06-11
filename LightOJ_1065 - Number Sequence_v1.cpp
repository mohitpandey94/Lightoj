/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-02-13 01:13:26
 * Problem   : 1065 - Number Sequence
 * CPU       : 0.156
 * Memory    : 1688
**/
#include <bits/stdc++.h>
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
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)
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
ll MOD;

void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (((F[0][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][0]%MOD)%MOD)%MOD);
  ll y =  (((F[0][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;
  ll z =  (((F[1][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD;
  ll w =  (((F[1][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;

  F[0][0] = x%MOD;
  F[0][1] = y%MOD;
  F[1][0] = z%MOD;
  F[1][1] = w%MOD;
}
void powmat(ll F[2][2], ll n) {
        if (n == 0 || n == 1) {
                return;
        }
        ll M[2][2] = {{1,1},{1,0}};
        powmat(F,n/2);
        multiply(F,F);
        if (n%2 != 0) multiply(F,M);
}

ll value (ll n, ll a, ll b, ll mod) {
        MOD = 1LL;
        for (int i=0; i < mod; i++) MOD *= 10;
        //cout<<MOD<<" ";
        ll F[2][2] = {{1,1},{1,0}};
        if (n == 0) return a;
        powmat(F,n-1);
        //cout<<F[0][0]<<" "<<F[0][1]<<"\n"<<F[1][0]<<" "<<F[1][1]<<"\n";
        //cout<<F[0][0]<< " ";
        ll ans = ((b*F[0][0]) + (a*F[0][1]))%MOD;
        return ans;
}

int main() {
        int t,a,b,m,i;
        ll n;
        t=readi();
        i=1;
        while (i<=t) {
                a=readi();b=readi();n=readl();m=readi();
                printf("Case %d: %lld\n",i,value(n,a,b,m));
                i++;
        }
return 0;
}
