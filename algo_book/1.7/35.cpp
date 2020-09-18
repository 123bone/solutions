#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (; n != 0; cin>>n){
		double cost[n];
		double avg = 0;
		for (auto &i : cost){
			cin>>i;
			avg += i;
		}
		// Take average cost, how much everyone pays after costs are equalized
		avg /= n;
		// Round average to two decimal places
		avg = int(avg * 100 + 0.5) / 100.0;
		// Students with greater cost than the average cost will take (their cost) - (avg.) and
		// add it to 'sum', which will be distributed among those with cost less than avg.
		// Those with less than avg. cost give nothing, so 'sum' is the answer.
		// Sum the differences of avg. and greater than avg. costs, and avg. and less than
		// avg. costs, and take min. of them as 'sum'.
		double sum_high = 0, sum_low = 0;
		for (auto i : cost){
			if (i > avg)
				sum_high += i - avg;
			else
				sum_low += avg - i;
		}
		double sum = min(sum_high, sum_low);
		cout<<fixed<<setprecision(2)<<"$"<<sum<<endl;
	}
}

