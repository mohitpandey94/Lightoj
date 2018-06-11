/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-01-08 03:00:42
 * Problem   : 1122 - Digit Count
 * CPU       : 0.624
 * Memory    : 1688
**/
#include <bits/stdc++.h>
using namespace std;
vector<int> s;
int n;
int rec (int str[], int pos) {
  if (pos == n) return 1;
  //cout<<str[0]<<" "<<str[1]<<" "<<str[2]<< ","<<pos<<"\n";
  int ans = 0;
  for (int i=0; i < s.size(); i++) {
    if (pos == 0) {
      str[pos] =s[i];
      ans += rec (str, pos+1);
    }
    else if (abs(str[pos-1]-s[i]) <= 2) {
        str[pos] = s[i];
        ans += rec (str, pos+1);
    }
  }
  return ans;
}
int main() {
  int t,m;
  int *str = NULL;
  cin>>t;
  for (int tc=1; tc<=t; tc++) {
    cin>>m>>n;
    s.clear();
    s.resize(m);
    str = new int[n];
    for (int i=0; i < m; i++) cin>>s[i];
    int ans = rec (str, 0); 
    cout<<"Case "<<tc<<": "<<ans<<"\n";
    delete str;
  }/*
  int str[3];
  str[0] = str[1] = str[2] = INT_MAX;
  cout<<rec(str,0);
  */
  return 0;
}