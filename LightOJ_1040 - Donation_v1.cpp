/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-09-27 02:25:28
 * Problem   : 1040 - Donation
 * CPU       : 0.012
 * Memory    : 1844
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
#define sl(a) scanf("%intd",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {int n=0,sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
ll readl () {ll n=0;ll sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
//
vector <vector<pair<int,int> > > graph;
class cmp {
	public:
		bool operator() (pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b) {
			return a.first.second > b.first.second;
		}
};
int prims (int n) {
	priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int> >, cmp > pq;
	//cout<<n<<"\n";
	bool vis[n+1];
	fill( vis, vis+n+1, false);
	pq.push(mp(mp(0,0),1));
	int id=1, cost=0,ans=0,countnodes = 0;
	while (!pq.empty()) {
		id = pq.top().second;
		cost = pq.top().first.first;

		if (vis[id]) {
			pq.pop();
			continue;
		}
		ans += pq.top().first.second;
		vis[id] = true;
		countnodes++;
		//cout<<id<<" "<<cost<<" "<<pq.top().first.second<<"\n";
		pq.pop();
		for (int i=0; i < graph[id].size(); i++) {
			//cout<<"This:";
			if (!vis[graph[id][i].first]) {
				pq.push(mp(mp(graph[id][i].second+cost,graph[id][i].second), graph[id][i].first));
				//cout<<graph[id][i].second+cost<<" "<<graph[id][i].second<<" "<<graph[id][i].first<<"\n";
			}
		}
	}
	//repu(i,1,n+1,1) {
		//cout<<i<<" ";
		if (countnodes < n) return 50000;
	//}
	

	return ans;
}
int main() {
    int t;
    int n,x,ans;
    t=readi();
    repu(tc,1,t+1,1) {
        n=readi();
        ans = 0;
        //vector<pair<int,int> > graph[n+1];
        graph.resize(n+1);
        repu(i,1,n+1,1) {
            repu(j,1,n+1,1) {
                x=readi();
                ans += x;
                if (i == j || !x) {
                    continue;
                }
                graph[i].pb(mp(j,x));
                graph[j].pb(mp(i,x));
            }
        }
        /*
        repu(i,1,n+1,1) {
          cout<<i<<":";
          repu(j,1,n+1,1) {
            cout<<graph[i][j].first<<" "<<graph[i][j].second<<"\n";
          }
          cout<<"\n";
        }
        */
        int ans2 = prims(n);
        //cout<<ans2<<" "<<ans<<"\n";
        if (ans2 == 50000) {
            printf("Case %d: %d\n",tc,-1);
        }
        else {
            printf("Case %d: %d\n",tc,(ans-ans2));
        }
        graph.clear();
    }

    return 0;
}