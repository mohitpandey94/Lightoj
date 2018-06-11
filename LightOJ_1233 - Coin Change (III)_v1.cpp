/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-06-03 13:33:43
 * Problem   : 1233 - Coin Change (III)
 * CPU       : 0.180
 * Memory    : 3456
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
int avl[100002], deno[102], cnt[102],freq[100005];

ll ways[100002];
ll itera (int ind, int k, int n) {
  for (int i=0;i<=100000;i++) ways[i] = 0;
  ways[0] = 1;
  avl[0] = k+1;
  for (int i=0; i < n; i++) {
  	for (int j=0; j <= k; j++) freq[j] = 0;
    for (int j=1; j <= k; j++) {
    	// if (j == 2 && deno[i] == 1) {
    	// 	cout<<"**"<<(j-deno[i])<<" "<<ways[j]<<" "<<freq[j-deno[i]]<<" "<<avl[j-deno[i]]<<"**\n";
    	// }
        if (j >= deno[i] && !ways[j] && (freq[j-deno[i]] < avl[deno[i]])){
          ways[j] += ways[j-deno[i]], ways[j] %= MOD;
          freq[j] += freq[j-deno[i]]+1;
        }
    }
    //cout<<"Ways:After"<<deno[i].ff<<"Coin: ";
    // for (int maxk=1; maxk <=k;  maxk++) cout<<ways[maxk]<<" "; cout<<"\n";
  }
  int ans=0;
  for (int i=1; i <=k;  i++) {
  	// cout<<ways[i]<<" ";
  	if (ways[i]) ans++;
  	
  }
  //cout<<"\n";
  return ans;
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
      cin>>avl[deno[i]];
      //cout<<deno[i]<<" "<<avl[i]<<"\n";
    }
    
    
    ll ways = itera (0, k, n);
    cout<<"Case "<<tc<<": "<<ways<<"\n";
  }
  return 0;
}