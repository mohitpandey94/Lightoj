/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-09-14 17:48:26
 * Problem   : 1281 - New Traffic System
 * CPU       : 0.300
 * Memory    : 3760
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

#define  ii pair<int, int>
#define  iii pair<int, ii>
#define  vii vector<ii>
#define  vi vector<int>
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
class cmp {
public:

    bool operator () (iii &a, iii &b) {
        return a.first > b.first;
    }
};
int dijkstra (vector <ii> graph[], vector <ii> proposed[], int n, int m, int k, int d) {
    int mindist[n+1][d+1];
    memset(mindist, 9999999, sizeof mindist);

    priority_queue <iii, vector <iii>, cmp> pq;

    int src=0, kused = 0, target = n-1, temptar, w;
    ii temp;
    mindist[src][kused] = 0;

    pq.push(mp(mindist[src][kused], mp(src,kused)));
    //cout<<"gdd";
    while (!pq.empty()) {
        src = pq.top().second.first;
        kused = pq.top().second.second;
        //cout<<src<<" "<<kused<<" "<<mindist[src][kused]<<"\n";
        if (src == target) return mindist[src][kused];
        pq.pop();
        //cout<<graph[src].size()<<":";
        repu(i,0,graph[src].size(),1) {
            temp = graph[src][i];
            temptar = temp.first, w = temp.second;
            //cout<<temptar<<" "<<w<<" "<<mindist[src][kused]<<" "<< mindist[temptar][kused]<<"\n";
            if (mindist[src][kused] + w < mindist[temptar][kused]) {
                mindist[temptar][kused] = mindist[src][kused] + w;
                pq.push(mp(mindist[temptar][kused], mp(temptar, kused)));
            }
        }
        //cout<<"pro";
        if (kused >= d) continue;
        //cout<<proposed[src].size()<<":";
        repu(i,0,proposed[src].size(),1) {
            //cout<<i;
            temp = proposed[src][i];
            temptar = temp.first, w = temp.second;
            //cout<<temptar<<" "<<w<<" "<<mindist[src][kused]<<" "<< mindist[temptar][kused]<<"\n";
            if (mindist[src][kused] + w < mindist[temptar][kused+1]) {
                mindist[temptar][kused+1] = mindist[src][kused] + w;
                pq.push(mp(mindist[temptar][kused+1], mp(temptar, kused+1)));
            }
        }
    }

    return -1;
}
int main() {
    int tc, n,m,k,d, x,y,z, ans;

    tc = readi();
    repu(t,1,tc+1,1) {
        n = readi(); m = readi(); k = readi(); d = readi();
        vector <pair<int,int> > graph[n+1];
        vector <pair<int,int> > proposed[n+1];
        repu(i,0,n+1,1)
            graph[i].clear();
        repu(i,0,n+1,1) proposed[i].clear();
        repu(i,0,m,1) {
            x = readi(), y = readi(), z = readi();
            graph[x].pb(mp(y,z));
        }
        //cout<<k<<" ";
        repu(i,0,k,1) {
            x = readi(), y = readi(), z = readi();
            //cout<<x<<" "<<y<<" "<<z<<"\n";
            proposed[x].pb(mp(y,z));
        }
        //cout<<proposed[x].size()<<"\n";
        //cout<<"gd";
        ans = dijkstra(graph, proposed, n, m, k, d);
        if (ans != -1)
            printf("Case %d: %d\n",t, ans);
        else
            printf("Case %d: Impossible\n",t);
    }
return 0;
}
