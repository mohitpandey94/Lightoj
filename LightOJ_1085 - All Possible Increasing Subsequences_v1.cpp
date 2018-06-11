/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-10-21 16:34:16
 * Problem   : 1085 - All Possible Increasing Subsequences
 * CPU       : 0.692
 * Memory    : 7484
**/
#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
#define MOD 1000000007
using namespace std;
int a[100005], b[100005], tree[100005];
map <int,int> mp;
void update (int idx, int val, int n) {
    while (idx <= n) {
        tree[idx] += val;
        if (tree[idx] >= MOD) tree[idx] %= MOD;
        idx += (idx & -idx);
    }
    return ;
}
int read (int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        ans %= MOD;
        idx -= (idx & -idx);
    }
    return ans;
}

int main() { 
    int t,n, ans;
    si(t);
    for (int tc = 1; tc <= t; tc++) {
        si(n);
        ans = 0;
        for (int i=0; i < n; i++) {
            si(a[i]);
            b[i] = a[i];
        }
        sort(b, b+n);
        int id = 1;
        mp[b[0]] = id;
        for (int i=1; i < n; i++) {
            if (b[i] != b[i-1]) {
                mp[b[i]] = ++id;
            }
        }
        for (int i=0; i < n; i++) {
            a[i] = mp[a[i]];
            //update(a[i], 1, n);
        }
        
        int fin = 0;
        for (int i=0; i < n; i++) {
        	///cout<<a[i]<<" "<<read(a[i]-1)<<" ";
            ans = read(a[i]-1)+1 ;
            fin += ans;
            fin %= MOD;
            update (a[i], ans, n);
            //cout<<ans<<" "<<fin<<",";
        }
        printf("Case %d: %d\n", tc, fin);
        memset (tree, 0, sizeof tree);
        memset (a, 0, sizeof a);
        mp.clear();
    }
    return 0;
}