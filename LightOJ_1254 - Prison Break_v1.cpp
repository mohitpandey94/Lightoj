/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-25 13:20:18
 * Problem   : 1254 - Prison Break
 * CPU       : 0.084
 * Memory    : 1736
**/
#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
vector<int> prices;
vector<vector<pii > > graph;
int mat[101][101];
class cmp {
public:
  bool operator () (pair<pii, int> a, pair<pii, int> b) {
    return a.second > b.second;
  }
};
int dijkstra (int src,  int tar, int c) {
  //vector<bool> vis(graph.size(), false);
  //map<pii, bool> vis;
  int vis[101][101];
  for (int i=0; i < 101; i++) for (int j=0; j < 101; j++) vis[i][j] = INT_MAX;
  priority_queue<pair<pii, int >, vector<pair<pii, int> >, cmp> pq;
  int ans = 0, tsrc, tc;
  pq.push(mp(mp(src, 0),ans));
  pair<pii, int> temp;
  vis[src][0] = 0;
  while (!pq.empty()) {
    temp = pq.top();
    tsrc = temp.first.first;
    tc = temp.first.second;
    ans = temp.second;
    pq.pop();
    if (vis[tsrc][tc]< ans) continue;
    //cout<<"\n\n"<<tsrc<<" "<<tc<<" "<<ans<<":\n";
    //vis[tsrc][tc] = ans;
    if (tsrc == tar) {
      return ans;
    }
    for (int i=0; i < graph[tsrc].size(); i++) {
      int node = graph[tsrc][i].first;
      int minreq = graph[tsrc][i].second;
      //cout<<"->"<<node<<" "<<minreq<<" "<<vis[mp(node, tc)]<<"\n";
      //if (!vis[mp(node,tc)]) {
      if (minreq > c) continue;
        if (tc >= minreq) {
            if (vis[node][tc-minreq] > vis[tsrc][tc]) {
                pq.push(mp(mp(node, tc-minreq),vis[tsrc][tc]));
                vis[node][tc-minreq] = vis[tsrc][tc];
            }
            //pq.push(mp(mp(node, 1),ans+(minreq-tc+1)*prices[tsrc]));

        }
    }
    if (tc+1 <= c) {
        vis[tsrc][tc+1] = vis[tsrc][tc]+prices[tsrc];
        pq.push(mp(mp(tsrc, tc+1),vis[tsrc][tc+1]));
    }
  }
  return -1;
}
int main() {
  int t,n,m,x,y,z,q,src,tar,c;
  cin>>t;
  for (int tc=1;tc<=t;tc++) {
    prices.clear();
    graph.clear();
    cin>>n>>m;
    prices.resize(n);
    graph.resize(n);

    for (int i=0; i < n; i++) cin>>prices[i];
    memset(mat, -1, sizeof mat);
    while (m--) {
      cin>>x>>y>>z;
      //graph[x][y] =graph[y][x]= min (graph[x][y] == 0 ? INT_MAX : graph[x][y], z);
      if (mat[y][x] == -1)
        mat[x][y] = min (min(mat[x][y] == -1? INT_MAX : mat[x][y], mat[y][x] == -1? INT_MAX : mat[y][x]), z);
      else
        mat[y][x] = min (min(mat[x][y] == -1? INT_MAX : mat[x][y], mat[y][x] == -1? INT_MAX : mat[y][x]), z);
    }
    for (int i=0; i < n; i++) {
        //cout<<i<<":\n";
        for (int j=0; j < n; j++) {

            if (mat[i][j] != -1) {
//                cout<<j<<" "<<mat[i][j]<<",";
                graph[i].pb(mp(j, mat[i][j]));
                graph[j].pb(mp(i, mat[i][j]));
            }
        }
    }
    //print graph
    /*for (int i=0; i < n; i++) {
        cout<<"\n"<<i<<":";
        for (int j=0; j < graph[i].size(); j++) {
            printf("(%d,%d)",graph[i][j].first, graph[i][j].second);
        }
    }*/

    cin>>q;
    cout<<"Case "<<tc<<":\n";
    while (q--) {
     cin>>c>>src>>tar;
     int ans = dijkstra(src, tar, c);
     if (ans == -1) {
       cout<<"impossible\n";
       }
      else {
        cout<<ans<<"\n";
      }
    }
  }
  return 0;
}
/*
1
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4
*/
