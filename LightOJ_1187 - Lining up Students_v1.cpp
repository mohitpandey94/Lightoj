/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2016-05-01 17:42:58
 * Problem   : 1187 - Lining up Students
 * CPU       : 0.308
 * Memory    : 1684
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,x;
    cin>>t;
    for (int tc=1;tc<=t;tc++) {
        cin>>n;
        cin>>x;
        int ans = 1;
        for (int i=2; i <=n ;i++) {
            cin>>x;
            if ((i-x) <= ans) ans++;
        }
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
return 0;
}
