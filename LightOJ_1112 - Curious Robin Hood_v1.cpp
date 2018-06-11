/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-10-21 14:12:06
 * Problem   : 1112 - Curious Robin Hood
 * CPU       : 0.240
 * Memory    : 2468
**/
#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;
int tree[100005];
int a[100005];
/*
void build (int idx, int n) {
	while (idx <= n) {
		tree[idx]
	}
}
*/
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
    int t,n,q,l,r,val,type,ans;
    si(t);
    for (int tc = 1; tc <= t; tc++) {
        si(n); si(q);
        for (int i=1; i<=n; i++) {
            si(a[i]);
        	update(i, a[i], n);
        }
        
        printf("Case %d:\n",tc);
        while (q--) {
            si(type);
            if (type == 1) {
                si(l);
                l++;
                cout<<a[l]<<"\n";
                update(l, -a[l], n);
                a[l] = 0;
            }
            else if (type == 2) {
                si(l), si(val);
                l++;
                update(l, val, n);
                a[l] += val;

            }
            else {
                si(l), si(r);
                l++; r++;
                //cout<<r<<" "<<l<<"::"<<query(r);//<<" "<<query(l-1)<<" ";
                ans = query(r) - query(l-1);
                printf ("%d\n", ans);
            }
        }
        memset(tree, 0, sizeof tree);
        memset(a, 0, sizeof a);
    }
    return 0;
}