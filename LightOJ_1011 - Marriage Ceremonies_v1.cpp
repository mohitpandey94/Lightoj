/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-15 07:38:35
 * Problem   : 1011 - Marriage Ceremonies
 * CPU       : 0.432
 * Memory    : 10396
**/
#include <bits/stdc++.h>
using namespace std;
vector <vector<int> > grid;
int memo[17][1<<17];
int recurse (int man, int mask, int n) {
  if (memo[man][mask])
    return memo[man][mask];
  for (int i=0; i < n; i++) {
    if (!(mask & 1<<i)) {
      memo[man][mask] = max(recurse(man+1, mask|1<<i,n)+grid[man][i],memo[man][mask]);
    }
  }
  return memo[man][mask];
}
int main() {
  vector <int> v;
  int t,n=3;
  cin>>t;
  for (int tc=1; tc<=t; tc++) {
    cin>>n;
    grid.resize(n);
    //v.resize(n);
    memset(memo, 0, sizeof memo);
    //for (int i=0; i < n; i++) v[i] = i;
    for (int i=0; i < n; i++) {
      grid[i].resize(n);
      for (int j=0; j < n; j++) {
        cin>>grid[i][j];
      }
    }
    int mask = 0;
    int sum= recurse(0, mask, n);
    cout<<"Case "<<tc<<": "<<sum<<"\n";
    grid.clear();
  }
  return 0;
}