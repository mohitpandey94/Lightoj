/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-26 11:48:01
 * Problem   : 1166 - Old Sorting
 * CPU       : 0.004
 * Memory    : 1688
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t,n;
  vector<int> a,b;
  cin>>t;
  for (int tc=1; tc<=t; tc++) {
    cin>>n;
    int ans = 0;
    a.resize(n);
    b.resize(n);
    for (int i=0;i<n;i++) cin>>a[i],b[i] = a[i];
    sort(b.begin(), b.end());
    for (int i=0; i < n; i++) {
      for (int j=0; j < n; j++) {
        if (b[i] == a[j] && j != i) {
          swap(a[i], a[j]);
          ans++;
        }
      }
    }
    //ans /= 2;
    printf("Case %d: %d\n",tc,ans);
    a.clear(); b.clear();   
  }
}