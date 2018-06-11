/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2018-06-07 00:31:32
 * Problem   : 1212 - Double Ended Queue
 * CPU       : 0.048
 * Memory    : 1688
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
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/mohit/coding/input.txt", "r", stdin);
    #endif
    int tc;
    string pushOp = "push";
    string pushLeft = "pushLeft";
    string popLeft = "popLeft";
    string failedPush = "The queue is full";
    string failedPop = "The queue is empty";
    string successPush = "Pushed in ";
    string successPop = "Popped from ";

    tc = readi();
    fu(tcc,1,tc+1) {
    	cout<<"Case "<<tcc<<":\n";
    	deque<int> d;
    	int n,m,x;
    	string inst;
    	n = readi(), m = readi();
    	while (m--) {
    		cin>>inst;
    		//cout<<n<<","<<d.size()<<","<<(d.size()<n)<<":::\n";
    		if (inst.substr(0,4) == pushOp) {
    			x = readi();
    			if (d.size() < n) {
    				if (inst == pushLeft) {
    					d.push_front(x);
    					cout<<successPush<<"left: "<<x;
    				} else {
    					d.push_back(x);
    					cout<<successPush<<"right: "<<x;
    				}
    			} else {
    				cout<<failedPush;
    			}
    		} else {
    			if (d.size() > 0) {
    				if (inst == popLeft) {
    					int temp = d.front();
    					d.pop_front();
    					cout<<successPop<<"left: "<<temp;
    				} else {
    					int temp =  d.back();
    					d.pop_back();
    					cout<<successPop<<"right: "<<temp;
    				}
    			} else {
    				cout<<failedPop;
    			}
    		}
    		cout<<endl;
    	}
    }

    return 0;
}