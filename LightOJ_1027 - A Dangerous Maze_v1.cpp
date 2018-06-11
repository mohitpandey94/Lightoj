/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-16 19:19:26
 * Problem   : 1027 - A Dangerous Maze
 * CPU       : 0.004
 * Memory    : 1688
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t,n,deno,neg,neu,pos;
  cin>>t;
  for (int tc=1; tc<=t;tc++) {
    cin>>n;
    vector <int> x(n,0);
    neg  = 0;
    for (int i=0; i < n; i++) {
      cin>>x[i];
      if (x[i] < 0) neg++;
    }
    deno = n-neg;
    cout<<"Case "<<tc<<": ";
    if (deno == 0) {
      cout<<"inf\n";
    }
    else {
      neu = 0;
      for (int i=0;i < n; i++) {
        neu += abs(x[i]);
      }
      int gcd = __gcd(neu, deno);
      cout<<(neu/gcd)<<"/"<<(deno/gcd)<<"\n";
    }
  }
  return 0;
}