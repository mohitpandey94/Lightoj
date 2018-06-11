/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-09-19 13:55:04
 * Problem   : 1379 - Toll Management
 * CPU       : 0.304
 * Memory    : 5784
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
#define sl(a) scanf("%lld",&a)
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
ll readl () {ll n=0;int sign=0;char c=gc();
while (c<48) {if (c==45) sign=1;c=gc();}
while (c>47) {n=n*10+c-'0';c=gc();}
if (sign) return (-n);	return n;
}
//
vector<ll> mincostsrc,mincosttar;

vector<vector<pair<ll,ll> > > graph, revgraph;
class cmp {
public:
    bool operator() (pair<ll,ll> &a, pair<ll,ll> &b) {
        return a.first < b.first;
    }
};
void dijkstra (vector<vector<pair<ll,ll> > > graph, ll src,ll n,vector<ll> &mincost) {
    //cout<<src<<":\n";
    priority_queue <pair<ll,ll>, vector <pair<ll,ll> >, cmp > pq;
    pq.push(mp(0,src));
    pair<ll,ll> temp;
    bool vis[n+1];
    ll node, cost;
    fill (vis, vis+n+1, false);

    while (!pq.empty()) {
        temp = pq.top();
        cost = temp.first;
        node = temp.second;
        //cout<<node<<" "<<cost<<"\n";
        pq.pop();
        vis[node] = true;
        mincost[node] = min(cost, mincost[node]);
        /*
        if (node == tar) {
            return;
        }
        */

        for (int i=0; i < graph[node].size(); i++) {
            if (!vis[graph[node][i].first]) {
                pq.push(mp(cost+graph[node][i].second, graph[node][i].first));
            }

            else {
                //mincost[graph[node][i].first] = min(mincost[graph[node][i].first], cost + graph[node][i].second);
                if (mincost[graph[node][i].first] > cost + graph[node][i].second) {
                    pq.push(mp(cost+graph[node][i].second, graph[node][i].first));
                }
            }

        }
    }
}
int main() {
    ll tc,n,m,s,t,p,x,y,w;
    ll u,v,z, maxcostedge;
    tc = readl();
    repu(tcc,1,tc+1,1) {
        n=readl(), m=readl(),s=readl(),t=readl(),p=readl();

        mincostsrc.resize(n+1);
        mincosttar.resize(n+1);
        graph.resize(n+1);
        revgraph.resize(n+1);

        repu(i,0,n+1,1) {
            mincostsrc[i] = p+10;
            mincosttar[i] = p+10;
        }

        repu(j,0,m,1) {
            x = readl(),y=readl(),w=readl();
            graph[x].pb(mp(y,w));
            revgraph[y].pb(mp(x,w));
            //edges[j].pb(mp(x,mp(y,z)));
        }
        //cout<<graph[5][0].first<<" "<<graph[5][1].first<<" "<<graph[5][2].first<<"\n";
        dijkstra(graph,s,n, mincostsrc);
        dijkstra(revgraph,t,n, mincosttar);
        //cout<<"\n
        maxcostedge = -10;
        repu(j,1,n+1,1) {
            repu(k,0,graph[j].size(),1) {
                u = j;
                v = graph[j][k].first;
                z = graph[j][k].second;
                //cout<<u<<" "<<v<<" "<<mincostsrc[s][u]<<" "<<mincosttar[t][v]<<" "<<z<<"\n";
                //if ((!mincostsrc[u] && u!=s) || (!mincosttar[v] && v != t)) continue;
                ll tempcost = mincostsrc[u] + z + mincosttar[v];
                if (tempcost <= p) {
                    maxcostedge = max (maxcostedge, z);
                }
            }
        }

        printf("Case %d: %lld\n", tcc, ((maxcostedge >= 0 && mincostsrc[t] != p+10)? maxcostedge : -1LL));
        mincostsrc.clear();
        mincosttar.clear();
        graph.clear();
        revgraph.clear();
    }
return 0;
}
