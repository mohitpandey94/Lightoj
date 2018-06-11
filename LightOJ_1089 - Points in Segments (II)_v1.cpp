/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-01 15:00:05
 * Problem   : 1089 - Points in Segments (II)
 * CPU       : 1.196
 * Memory    : 19644
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
#ifdef ONLINE_JUDGE
#define gc getchar_unlocked
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define gc getchar
#endif // ONLINE_JUDGE
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

vector<int> v;
vector< pii > ranges;
map<int,bool> isthere;
map<int,int> mp1, mp2;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Mohit Kumar Pandey\\Desktop\\IP_ass/input.txt", "r", stdin);
    freopen("C:\\Users\\Mohit Kumar Pandey\\Desktop\\IP_ass/output.txt", "w", stdout);
    #endif
	int q,t,n,a,b;
	t=readi();
	fu(tc,1,t+1) {
		n=readi(), q=readi();
		rep(i,n) {
			a=readi(), b=readi();
			if(a>b) swap(a,b);
			ranges.pb(mp(a,b));
			if (!isthere[a]) {
				v.pb(a);
				isthere[a]=true;
			}
			if (!isthere[b]) {
				v.pb(b);
				isthere[b]=true;
			}
		}
		sort(v.begin(),v.end());
		int cnt=1;
		rep(i,v.size()) {
			mp1[v[i]] = cnt;
			cnt+=2;
		}
		rep(i,ranges.size()) {
			mp2[mp1[ranges[i].ff]]++; mp2[mp1[ranges[i].ss]+1]--;
		}
		fu(i,1,cnt) {
			mp2[i] += mp2[i-1];
		}
		printf("Case %d:\n",tc);
		while (q--) {
			a=readi();
			int id = lower_bound(v.begin(),v.end(),a)-v.begin();
			if (id == v.size()) {
				printf("0\n"); continue;
			}
			int xx = mp1[v[id]];
			if (v[id] > a) {
                xx--;
//				printf("%d\n",xx);
			}
            printf("%d\n",mp2[xx]);
		}
		v.clear();ranges.clear();
		isthere.clear();
		mp1.clear(), mp2.clear();
	}
	return 0;
}
