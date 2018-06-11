/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-10-21 14:38:21
 * Problem   : 1080 - Binary Simulation
 * CPU       : 0.260
 * Memory    : 2080
**/
#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;
int tree[100005];

void update (int idx, int val, int n) {
    while (idx <= n) {
        tree[idx] += val;
        idx += (idx&(-idx));
    }
    return ;
}
int query (int idx) {
    int ans = 0;
    //cout<<"\n:::"<<idx<<"\n";
    while (idx > 0) {
        ans += tree[idx];
        idx -= (idx&(-idx));
        //cout<<ans<<" ";
    }
    //cout<<"\n:::\n";
    return ans;
}
int main() {
    int t,n,q,l,r,val,ans;
    char s[100005];
    char type;
    si(t);
    for (int tc = 1; tc <= t; tc++) {
        scanf(" %s", &s);
        n = strlen(s);
        si(q);
        printf("Case %d:\n", tc);
        while (q--) {
            scanf(" %c", &type);
            if (type == 'I') {
                si(l), si(r);
                update(l, 1,n );
                update(r+1, -1, n);
            }
            else {
                si(l);
                ans = query(l);
                //cout<<ans<<" ";
                if (!(ans&1)) printf("%c\n", s[l-1]);
                else {
                    printf("%c\n",(s[l-1] == '0'? '1' :'0'));
                }
            }
        }
        memset(tree, 0, sizeof tree);
    }
    return 0;
}