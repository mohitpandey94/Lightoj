/**
 * Author    : mohitpandey94
 * Lang      : C++
 * Date      : 2018-04-19 00:28:46
 * Problem   : 1038 - Race to 1 Again
 * CPU       : 1.016
 * Memory    : 2480
**/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double memo[100005];
double recurse(int n) {
	if (n == 1) return memo[n]=0.0;
	//if (n == 2) return 2.0;
	//cout<<n<<","<<memo[n]<<endl;
	if (memo[n] != -1.0) return memo[n];
	double ans = 0.0;
	int cnt = 2;
	for (int k = 2; k <= sqrt(n+1); k++) {
		if (n%k == 0) {
			ans += recurse(k)+1;
			//cout<<ans<<" "<<k<<"::";
			cnt++;
			if (n/k != k) {
				cnt++;
				ans += recurse(n/k)+1;
			//	cout<<ans<<" "<<n/k<<"::\n";
			}
			//cout<<endl;
		}
	}
	if (ans == 0.0) {
		return memo[n] = 2.0;
	}
	//cout<<n<<","<<ans<<","<<cnt<<endl;
	return memo[n] = (((ans*1.0)/(cnt*1.0))+(2.0/(cnt*1.0)))*((cnt*1.0)/((cnt-1)*1.0));
}
int main() {
	std::cout << std::setprecision(6) << std::fixed;
	int t,n;
	cin>>t;
	for (int tc=1; tc<=t; tc++) {
		cin>>n;
		for (int i=0; i < 100005; i++) memo[i] = -1.0;
		cout<<"Case "<<tc<<":"<<" "<<recurse(n)<<endl;
		/*for (int i=1; i <= n; i++) {
			if (memo[i]!=-1.0)
				cout<<i<<":"<<memo[i]<<"\n";
		}
		cout<<endl;*/
	}
	return 0;
}