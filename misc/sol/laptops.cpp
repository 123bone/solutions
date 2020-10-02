#include <bits/stdc++.h>
using namespace std;

int main(){
	int mxN = 100001;
	int n;
	cin>>n;
	int a[n];
	int q[mxN];
	for(int i = 0; i < n; ++i){
		cin>>a[i]>>q[a[i]];
	}
	sort(a, a+n);
	bool happy = false;
	for(int i = 0; i < n - 1; ++i){
		if(q[a[i]] > q[a[i + 1]])
			happy = true;
	}
	cout<<(happy ? "Happy Alex" : "Poor Alex");
}
