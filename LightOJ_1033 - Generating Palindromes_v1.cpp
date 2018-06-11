/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-16 20:00:36
 * Problem   : 1033 - Generating Palindromes
 * CPU       : 0.168
 * Memory    : 1728
**/
#include <bits/stdc++.h>
using namespace std;
int memo[102][102];
int lcs (string s, string rs, int n, int m) {
  if (!n || !m) return 0;
  if (memo[n][m] != -1) return memo[n][m];
  if (s[n-1] == rs[m-1]) {
    memo[n][m] =  1 + lcs (s, rs, n-1, m-1);
  }
  else {
    memo[n][m] =  max (lcs (s, rs, n-1,m), lcs (s, rs, n, m-1));
  }
  return memo[n][m];
}
void reset() {
  for (int i=0; i <= 100; i++)
    for (int j=0; j <= 100; j++)
      memo[i][j] = -1;
}
int main() {
  string s, rs;
  int t;
  cin>>t;
  for (int tc=1; tc<=t;tc++) {
    cin>>s;
    rs = s;
    reverse(rs.begin(), rs.end());
    //cout<<s<<" "<<rs<<"\n";
    reset();
    int len = lcs (s, rs,s.length(),rs.length());
    cout<<"Case "<<tc<<": "<<(s.length()-len)<<"\n";
  }
  return 0;
}