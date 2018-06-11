/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-10-21 17:04:17
 * Problem   : 1266 - Points in Rectangle
 * CPU       : 0.356
 * Memory    : 6620
**/
#include <bits/stdc++.h>
#define si(x) scanf("%d",&x)
using namespace std;
#define MAXX 1005
#define MAXY 1005

int tree[MAXX][MAXY];
bool present[MAXX][MAXY];
void update (int x, int y, int val) {
    int y1;
    while (x <= MAXX) {
        y1 = y;
        while (y1 <= MAXY) {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
    return ;
}
int read (int x, int y) {
    int y1,ans = 0;
    while (x > 0) {
        y1 = y;
        while (y1 > 0) {
            ans += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ans;
}
int main() {
    int t,q,type,x1,y1,x2,y2;
    si(t);
    for (int tc = 1; tc <= t; tc++) {
        si(q);
        int ans = 0;
        printf("Case %d:\n", tc);
        while (q--) {
            si(type);
            if (type == 0) {
                si(x1), si(y1);
                x1++; y1++;
                if (!present[x1][y1])
                    update (x1, y1, 1);
                //cout<<tree[x1][y1]<<":::\n";
                present[x1][y1] = true;
            }
            else {
                si(x1), si(y1), si(x2), si(y2);
                x1++; y1++;
                x2++; y2++;
                ans = read (x2,y2) - read(x2,y1-1)-read(x1-1,y2)+read(x1-1, y1-1);
                printf("%d\n", ans);
            }
        }
        memset(tree, 0, sizeof tree);
        memset (present, 0, sizeof present);
    }
} 