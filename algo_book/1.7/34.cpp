// https://onlinejudge.org/external/1/100.pdf
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// Brute force
	int a, b;
	while (cin>>a>>b){
		int mx = -10e6;
		for (int i = min(a, b); i <= max(a, b); ++i){
			int n = i, len = 1;
			while (n > 1){
				++len;
				if (n & 1)
					n = 3 * n + 1;
				else
					n /= 2;
			}
			mx = max(len, mx);
		}
		cout<<a<<" "<<b<<" "<<mx<<endl;
	}
}
