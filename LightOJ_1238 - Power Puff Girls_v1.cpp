/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-05-21 04:14:20
 * Problem   : 1238 - Power Puff Girls
 * CPU       : 0.000
 * Memory    : 1692
**/
#include <bits/stdc++.h>
#include <cstring>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
char place[20][20];
bool vis[20][20];
const int dx[] = {-1,1};
const int dy[] = {-1,1};
int ans;
void bfs (int x, int y, int w, int h, int dist[21][21]) {
    memset (vis,false,sizeof vis);
    memset (dist,-1,sizeof dist);
    queue <pair <int,int> > q;
    q.push(mp(x,y));
    ans = 1;
    int i,j;
    vis[x][y] = true;
    dist[x][y] = 0;
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        //cout<<"("<<i<<","<<j<<")\n";

        repu(ind,0,2,1) {
            if (!vis[i+dy[ind]][j] && (place[i+dy[ind]][j] != 'm' && place[i+dy[ind]][j] != '#') && (i+dy[ind] >= 0 && i + dy[ind] < h)) {
                q.push(mp(i+dy[ind],j));
                vis[i+dy[ind]][j] = true;
                dist[i+dy[ind]][j] = dist[i][j] + 1;
            }
            if (!vis[i][j+dx[ind]] && (place[i][j+dx[ind]] != 'm' && place[i][j+dx[ind]] != '#') && (j+dx[ind] >= 0 && j + dx[ind] < w)) {
                q.push(mp(i,j+dx[ind]));
                vis[i][j+dx[ind]] = true;
                dist[i][j+dx[ind]] = dist[i][j] + 1;
            }
        }

    }

}
int main() {
    int t,w,h,dista[21][21],distb[21][21],distc[21][21], homx,homy;
    t = readi();
    repu(i,1,t+1,1) {
        h = readi(); w = readi();
        //char place[h][w];
        repu(j,0,h,1) {
            scanf("%s",&place[j]);
        }
        repu(j,0,h,1) {
            repu(k,0,w,1) {
                if (place[j][k] == 'a') {
                    bfs (j,k,w,h,dista);
                }
                else if (place[j][k] == 'b') {
                    bfs (j,k,w,h,distb);
                }
                else if (place[j][k] == 'c') {
                    bfs (j,k,w,h,distc);
                }
                else if (place[j][k] == 'h') {
                    homx = j;
                    homy = k;
                }
            }
        }
        ans = INT_MIN;
        repu (j,0,h,1) {
            repu (k,0,w,1) {
                ans = max (dista[homx][homy],max(distb[homx][homy], distc[homx][homy]));
            }
        }
        cout<<"Case "<<i<<": "<<ans<<"\n";
        ans = 0;
    }
return 0;
}
