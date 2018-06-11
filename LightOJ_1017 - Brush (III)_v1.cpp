/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-01-01 17:12:45
 * Problem   : 1017 - Brush (III)
 * CPU       : 0.016
 * Memory    : 1768
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pointsy[101],w,n,k;
ll memo[101][101];
ll rec (int ind, int mvs) {
  if (ind >= n || !mvs) return 0;
  if (memo[ind][mvs] != -1) 
    return memo[ind][mvs];
  int curEnd = pointsy[ind] + w,i;
  ll reach = 0;
  for (i = ind; i < n && pointsy[i] <= curEnd; i++) {
    reach++;
  }
  reach += rec(i, mvs-1);
  ll skip = rec (ind + 1, mvs);
  memo[ind][mvs] = max (reach, skip);
  return memo[ind][mvs];
}
int main() {
  int t,temp;
  cin>>t;
  for (int tc=1; tc<=t;tc++) {
    cin>>n>>w>>k;
    for (int i=0; i < n; i++) {
      cin>>temp>>pointsy[i];
    }
    memset(memo, -1, sizeof memo);
    sort(pointsy, pointsy+n);
    ll ans = rec(0, k);
    printf("Case %d: %lld\n", tc, ans);
  }
  return 0;
}