/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-16 05:54:15
 * Problem   : 1047 - Neighbor House
 * CPU       : 0.004
 * Memory    : 1688
**/
#include <bits/stdc++.h>
using namespace std;
int memo[22][4];
int rgb[22][4];
int recurse (int house, int color, int n) {
  //cout<<house<<" "<<color<<"\n";
  if (house == n) return 0;
  if (memo[house][color]) {
    //cout<<"Exec.\n";
    return memo[house][color];
  }
  for (int i=0; i < 3; i++) {
    if (i != color) {
      //cout<<"House"<<house<<"color"<<i<<"\n";
      memo[house][color] = min (memo[house][color] == 0?100000 : memo[house][color], recurse (house+1, i,n) + rgb[house][i]); 
    }
  }
  return memo[house][color];
}
int main() {
  int n,t;
  cin>>t;
  for (int tc=1; tc<=t; tc++) {
    cin>>n;
    //int rgb[n][3];
    for (int i=0; i < n; i++) {
      for (int j=0; j < 3; j++) {
        cin>>rgb[i][j];
      }
    }
    memset (memo,0, sizeof memo);
    int ans = recurse (0, 3, n);
    cout<<"Case "<<tc<<": "<<ans<<"\n";
  }
  return 0;
}