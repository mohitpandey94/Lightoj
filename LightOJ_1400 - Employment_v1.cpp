/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2015-09-27 23:27:04
 * Problem   : 1400 - Employment
 * CPU       : 0.028
 * Memory    : 1692
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%intd",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (int i = a; i < n; i += step)
#define repd(i,a,n,step) for (int i = a - 1; i >= n; i -= step)
using namespace std;
int readi () {int n=0,sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
ll readl () {ll n=0;ll sign=0;char c=gc();
	while (c<48) {if (c==45) sign=1;c=gc();}
	while (c>47) {n=n*10+c-'0';c=gc();}
	if (sign) return (-n);	return n;
}
//lightoj 1400
//
int existsfreeman (int maneng[], int n) {
    repu(i,1,n+1,1) {
    	//cout<<i<<" "<<maneng[i]<<"\n";
        if (maneng[i] == -1) return i;
    }
    return -1;
}
void stableMarriage (vector< int > man[] , vector< int > woman[], int n) {
    int maneng[n+1];
    int womaneng[2*n+1];
    bool tried[n+1][2*n+1];
    //memset(tried, false, sizeof tried);
    repu(i,1,n+1,1) {
    	repu(j,1,n+1,1)
    		tried[i][n+j] = false;
    	maneng[i] = -1;
    	womaneng[i+n] = -1;
    }
	
    queue <int> q;
  	repu(i,1,n+1,1) q.push(i);
	int curm, curw;    
	while (!q.empty()) {
       curm = q.front();
	   q.pop();
	   //cout<<curm<<" ";
	   for (int w = 0; w < man[curm].size() && maneng[curm] == -1; w++) {
			curw = man[curm][w];
			if (womaneng[curw] == -1) {
				womaneng[curw] = curm;
				maneng[curm] = curw;
				man[curm].erase(find(man[curm].begin(), man[curm].end(),curw));
			}
			else {
				int prefm, prefo;
				prefm = 0, prefo = -1;
				for (int m = 0; m < woman[curw].size(); m++) {
					if (woman[curw][m] == curm) {
						prefm = m;
					}
					if (woman[curw][m] == womaneng[curw]) {
						prefo = m;
					}
				}
				if (prefm < prefo) {
					maneng[womaneng[curw]] = -1;
					q.push(womaneng[curw]);
					maneng[curm] = curw;
					womaneng[curw] = curm;				
				}			
			}
		}
		//cout<<maneng[curm]<<"\n";
    }
    
    repu(i,1,n+1,1) {
    	//if (i > 1) cout<<" ";
        cout<<" ("<<i<<" "<<maneng[i]<<")";
    }
    cout<<"\n";
}
int main() {
    int t,n,pref;
    t=readi();
    repu(tc,1,t+1,1) {
        n=readi();
        vector<int> cand[n+1];
        vector<int> comp[2*n+1];

        repu(i,1,n+1,1) {
            repu(j,1,n+1,1) {
                pref = readi();
                cand[i].pb(pref);
            }
        }
        
        repu(i,1,n+1,1) {
            repu(j,1,n+1,1) {
                pref = readi();
                comp[n+i].pb(pref);
            }
        }
        cout<<"Case "<<tc<<":";
        stableMarriage(cand, comp, n);
    }
    return 0;
}
