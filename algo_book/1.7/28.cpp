// Perform integer division without using either * or / operators
#include <bits/stdc++.h>
using namespace std;

int divide(int a, int b){
	// Base cases
	if (a == 0 || b == 0)
		return 0;
	int sign = (a < 0 ^ b < 0) ? -1 : 1;
	a = abs(a), b = abs(b);
	if (b == 1)
		return a * sign;

	// Compute max. mid such that mid * b <= a, or mid = floor(a/b), with lower bound binary search
	int left = 1, mid = 0, right = a;
	while (left < right){
		mid = left + ((right - left) >> 1);
		int sum = mid;
		// Compute sum = mid * b by repeated addition
		for (int i = 1; i < b; ++i){
			if (sum > a) // early exit
				break;
			sum += mid;
		}
		if (sum > a)
			right = mid;
		else
			left = mid + 1;
	}
	return (left - 1) * sign;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<divide(a,b)<<endl;
}
