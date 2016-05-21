#include <bits/stdc++.h>
#define fu(i, a, n) for (int i = a; i < n; i++)
#define fd(i, n, a) for (int i = n; i >= a; i--)
#define rep(i,n) fu(i,0,n)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define sl(x) scanf("%lld", &x); //sl(x) is for long long int.
#define si(x) scanf("%d", &x);
#define pl(x) printf("%lld", x);  //pl(x) is for long long int.
#define pi(x) printf("%d", x);
#define gc getchar_unlocked
#define ll long long
#define ff first
#define ss second
using namespace std;
int readi() {int n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
ll readl() {ll n=0,sign=false;char c = gc();
	while (c < '0' || c > '9') { if (c == '-') sign=true; c=gc();}
	while (c>='0' && c<='9') {n=n*10+c-'0';c=gc();}
	if (sign) return -n; return n;
}
int gid (char c) {
	if (c >= 'A' && c <= 'Z') return (c-'A');
	else return (c-'a')+26;
}
/*struct node {
	node* childs[55];
	// bool isleaf;
	int cnt;
} *root;
struct node* newnode() {
	struct node* temp = new node;
	rep(i,55) temp->childs[i] = NULL;
	// temp->isleaf = false; 
	temp->cnt = 0;
	return temp;
}
void insert (string s) {
	node* temp = root;
	int sz = s.size();
	rep(i,sz) {
		if (!(temp->childs[gid(s[i])])) {
			temp->childs[gid(s[i])] = newnode();
		}
		temp = temp->childs[gid(s[i])];
	}
	// temp->isleaf = true;
	temp->cnt++;
}
int search (string s) {
	node *temp = root;
	int sz = s.size();
	rep(i,sz) {
		if (!(temp->childs[gid(s[i])])) return 0;
		temp = temp->childs[gid(s[i])];
	}
	return temp->cnt;
}
void clearll (struct node* root) {
	for(int i=0;i<55;i++) {
		if (root->childs[i]) {
			clearll(root->childs[i]);
			free (root->childs[i]);
		}
	}
	return ;
}*/
int trie[100000][55];
bool isthere[100000][55];
int counter[100000],tot;
void insert (string s) {
	int node = 0,sz = s.size();
	rep(i,sz) {
		if (!isthere[node][gid(s[i])]) {
			trie[node][gid(s[i])] = tot;
			isthere[node][gid(s[i])] = true;
			tot++;
		}
		node = trie[node][gid(s[i])];
	}
	counter[node]++;
}
int search (string s) {
	int node = 0, sz = s.size();
	rep(i,sz) {
		if (!isthere[node][gid(s[i])]) return 0;
		node = trie[node][gid(s[i])];
	}
	return counter[node];
}
int main () {
	#ifndef ONLINE_JUDGE
    freopen("/home/sherlock/input.txt", "r", stdin);
    #endif
    int t,n,m;
    int res = 1;
    t=readi();
    char temp[100000];
    string s;
    fu(tc,1,t+1) {
    	// root = newnode();
    	tot=1;
    	res =1;
    	n=readi();
    	memset(isthere,false,sizeof(isthere));
    	memset(counter,false,sizeof(counter));
    	rep(i,n) {
    		gets(temp);
	    	s = (string)(temp);
	    	if(s.size() > 2)
				sort(s.begin()+1,s.end()-1);
			insert(s);    		
    	}
    	m=readi();
    	string str="";
    	s="";

    	printf("Case %d:\n", tc);
    	while (m--) {
    		s="";
    		str="";
    		gets(temp);
    		s = (string)(temp);
    		int sz = s.size();
    		// cout<<s<<":";
    		
    		/*if (sz == 0) {
    			printf("1\n");
    			continue;
    		}*/
    		rep(i,sz) {
    			// cout<<i<<" "<<str<<"::";
    			if (s[i] != ' ') {
    				str += s[i];
    			}
    			else {
    				if(str.size()>2)
						sort(str.begin()+1,str.end()-1);
					if(str.size()>0)
    					res = res * search(str);
    				// cout<<res<<" "<<str<<",";
    				str = "";
    			}
    			if (i == sz-1) {
    				// cout<<i<<" "<<str<<"\n";
    				if(str.size()>2)
    					sort(str.begin()+1,str.end()-1);
    				if(str.size()>0)
    					res = res * search(str);
    				// cout<<res<<" "<<str<<",";
    				str = "";
    			}
    		}
    		printf("%d\n",res);
    		res = 1;
    	}
    	
    	/*clearll(root);
    	free (root);*/
    }
    return 0;
}