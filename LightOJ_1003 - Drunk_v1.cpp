/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-02-14 02:17:24
 * Problem   : 1003 - Drunk
 * CPU       : 0.192
 * Memory    : 2592
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
map <string, int> mapper;
vector <int> v[10005];
bool checkcycleDfs(int j, bool visited[], bool stck[]) {
        if (!visited[j]) {
                visited[j]=true;
                stck[j]=true;
                for (int k=0; k < v[j].size(); k++) {
                        if (!visited[v[j][k]] && checkcycleDfs(v[j][k],visited,stck))
                                return true;
                        else if (stck[v[j][k]]) return true;
                }
        }
        stck[j] = false;
        return false;
}
int main() {
        int t,i,n,key=0,j,flag=0;
        string x,y;
        t=readi();
        i=1;
        for (;i<=t;i++) {
                n=readi();
                j=0;
                while (j<n) {
                        cin>>x>>y;
                        if (!mapper[x]) {
                                mapper[x] = key;
                                key++;
                        }
                        if (!mapper[y]) {
                                mapper[y] = key;
                                key++;
                        }
                        //cout<<x<< " "<<mapper[x]<<"\n"<<y<<" "<<mapper[y]<<"\n";
                        v[mapper[x]].pb(mapper[y]);
                        j++;
                }
                /*for (j=0; j < key; j++) {
                        for (int k=0; k != v[j].size(); k++) {
                                cout<<j<<"->"<<v[j][k]<<" ";
                        }
                        cout<<"\n";
                }*/
                bool visited[key];
                bool stck[key];
                memset(visited,0,sizeof(visited));
                memset(stck,0,sizeof(visited));

                for (j=0;j<key;j++) {
                        if(checkcycleDfs(j,visited,stck)) {
                                flag=1;
                                break;
                        }
                }
                if (flag) printf("Case %d: No\n",i);
                else printf("Case %d: Yes\n",i);
                for (j=0; j < key; j++) v[j].clear();
                key=flag=0;
                mapper.clear();

        }
return 0;
}
