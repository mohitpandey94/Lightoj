/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-01-07 13:09:10
 * Problem   : 1025 - The Specials Menu
 * CPU       : 0.008
 * Memory    : 1720
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string temp;
ll memo[65][65];

ll rec (int i, int j) {
  if (i == j) return 1;
  if (i > j) return 0;
  if (memo[i][j] != -1) return memo[i][j]; 
  //cout<<temp[i]<<" "<<temp[j]<<"\n";
  
  ll ans = rec(i+1,j) + rec (i,j-1) - (1- (temp[i] == temp[j]))*rec(i+1,j-1) + (temp[i]==temp[j]);
  memo[i][j] = ans;
  
  return ans;
}
int main() {
  int t;
  cin>>t;
  for (int tc=1; tc<=t;tc++) {
    cin>>temp;
    memset(memo, -1, sizeof (memo));
    ll ans = rec(0, temp.length()-1);
    printf("Case %d: %lld\n", tc,ans);
  }
  return 0;
}