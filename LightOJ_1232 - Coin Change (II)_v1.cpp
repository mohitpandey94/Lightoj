/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-16 11:21:09
 * Problem   : 1232 - Coin Change (II)
 * CPU       : 0.288
 * Memory    : 1972
**/
/*
   3 5
   1 2 5  3 2 1
   4 20
   1 2 3 4 8 4 2 1 
 */
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define MOD 100000007
#define pii pair<int,int>
using namespace std;
int memo[1002][52];
int deno[102], cnt[102];
ll recurse (int ind, int k, int n) {
  //cout<<ind<<" "<<k<<"\n";
  if (k == 0) return 1;
  if (ind == n || k < 0) return 0;
  if (memo[k][ind] != -1) return memo[k][ind];
  ll ways =0;
  int tot = cnt[ind];
  for (int i=0; i <= tot; i++) {
    ways = (ways+recurse (ind+1, k-i*deno[ind], n))%MOD;
    //if (ways >= MOD) ways %= MOD;
  }
  //ways += recurse (deno, ind+1, k, n);
  //if (ways >= MOD) ways %= MOD;
  memo[k][ind] = ways;
  return ways;
}

ll ways[10002];
ll itera (int ind, int k, int n) {
  /*
  if (ind == n) {
    if (k == 0) return 1;
    return 0;
  }
  if (k == 0) return 1;
  if (k < 0) return 0;
  if (memo[k][ind] != -1) return memo[k][ind];
  */
  //memset(ways,0,sizeof ways);
  for (int i=0;i<=10000;i++) ways[i] = 0;
  ways[0] = 1;
  for (int i=0; i < n; i++) {
    for (int j=deno[i]; j <= k; j++) {
      //for (int coin=1; coin <= cnt[i]; coin++) {
        //if (j-coin*deno[i] >= 0)
        //if (j >= deno[i])
          ways[j] += ways[j-deno[i]], ways[j] %= MOD; 
      //}
    }
    //cout<<"Ways:After"<<deno[i].ff<<"Coin: ";
    //for (int maxk=0; maxk <=k;  maxk++) cout<<ways[maxk]<<" "; cout<<"\n";
  }
  //for (int i=0; i <=k;  i++) cout<<ways[i]<<" "; cout<<"\n";
  return ways[k];
}

int main() {
  int n, k,t;
  cin>>t;
  for (int tc=1;tc<=t; tc++) {
    cin>>n>>k;
    //vector <pair<int,int> > deno(n);
    //vector <int> used(n, 0);
    for (int i=0; i < n; i++) {
      cin>>deno[i];
    }
    for (int i=0; i < n; i++) {
      cnt[i]=k;
    }
    /*
    memset (ways, 0, sizeof ways);
    for (int i=0; i <= 1001; i++)
      for (int j=0; j <= 51; j++)
        memo[i][j] = -1;
    */
    ll ways = itera (0, k, n);
    cout<<"Case "<<tc<<": "<<ways<<"\n";
  }
  return 0;
}