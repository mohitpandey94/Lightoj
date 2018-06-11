/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-12-17 22:32:12
 * Problem   : 1013 - Love Calculator
 * CPU       : 0.004
 * Memory    : 1700
**/
#include <bits/stdc++.h>
using namespace std;
int memo[32][32];
long long memo2[32][32];
long long cnt;
/*
   int lcs (string s, string rs, int n, int m) {
   if (!n || !m) return 0;
   if (memo[n][m] != 0) return memo[n][m];
   if (s[n-1] == rs[m-1]) {
   memo[n][m] =  1 + lcs (s, rs, n-1, m-1);
   memo2[n][m] = memo2[n-1][m-1]; //since both chars match there is not any increment in the number of strings possible, as both the chars need to be there
   }
   else {
   memo[n][m] =  max (lcs (s, rs, n-1,m), lcs (s, rs, n, m-1));
   if (memo[n-1][m] == memo[n][m-1])
   memo2[n][m] = memo2[n-1][m] + memo2[n][m-1];//if removal of both chars give the same lcs, then we can choose either chars as both will yeild us the same output.
   else if (memo[n-1][m] > memo[n][m-1])
   memo2[n][m] = memo2[n-1][m]; //if the above condition is not satisfied then choose the char which yeilds us the max length of lcs.
   else 
   memo2[n][m] = memo2[n][m-1];
   }
   return memo[n][m];
   }
 */
void reset() {
  memset (memo, 0, sizeof memo);
  memset (memo2, 0, sizeof memo2);
  for (int i=0; i <= 31; i++)
    for (int j=0; j <= 31; j++)
      memo[i][j] = 0;
  for (int i=0; i<= 31; i++) memo2[i][0] = memo2[0][i] = 1;
  cnt = 0;
}
/*
   void count (string s, string rs, int n, int m) {
   for (int i=1; i<= n; i++) {
   for (int j=1; j<=m; j++) {
   if (s[i-1] == 
   }
   }
   }
 */
int iter (string s, string rs, int n, int m) {
  for (int i=0; i <= 31; i++) memo[i][0] = memo[0][i] = 0;
  for (int i=0; i <= 31; i++) memo2[i][0] = memo2[0][i] = 1;

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (s[i-1] == rs[j-1]) {
        memo[i][j] = memo[i-1][j-1]+1;
        memo2[i][j] = memo2[i-1][j-1];
      }

      else {
        memo[i][j] = max (memo[i-1][j], memo[i][j-1]);
        if (memo[i-1][j] == memo[i][j-1]) 
          memo2[i][j] = memo2[i-1][j]+memo2[i][j-1];
        else if (memo[i-1][j] > memo[i][j-1]) 
          memo2[i][j] = memo2[i-1][j];
        else 
          memo2[i][j] = memo2[i][j-1];
      }
    }
  }
  //count(s, rs, n, m);
  return memo[n][m];

}
int main() {
  string s, rs;
  int t;
  cin>>t;
  for (int tc=1; tc<=t;tc++) {
    cin>>s;
    cin>>rs;
    //rs = s;
    //reverse(rs.begin(), rs.end());
    //cout<<s<<" "<<rs<<"\n";
    reset();
    //int len = lcs (s, rs,s.length(),rs.length());
    int len = iter (s, rs, s.length(), rs.length());
    cnt = memo2[s.length()][rs.length()];

    cout<<"Case "<<tc<<": "<<(s.length()+rs.length()-len)<<" "<<cnt<<"\n";
    /*
       for (int i=0; i <= s.length(); i++) { 
       for (int j=0; j <= rs.length(); j++)
       cout<<memo[i][j]<<" ";
       cout<<"\n";
       }
     */

  }
  return 0;
}