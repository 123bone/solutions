#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	// Let a valid parantheses sequence be a substring where each '(' has a matching ')', and all pairs between them are also valid.
	// Ex. in '()(()())())', the '()' and '(()())' are valid sequences, but not '())'.
	// Depth of current parantheses sequence
	stack<int> depth;
	// Ending index of last valid parantheses sequence
	int j = 0;
	for (int i = 0; i < s.size(); ++i){
		if (s[i] == '('){
			// Increase depth
			depth.push(1);
		}else{
			if (depth.empty()){
				// No unclosed '(' exist
				cout<<"FALSE: "<<i<<endl;
				return 0;
			}
			// Decrease depth
			depth.pop();
			// Depth is zero, current sequence is now the last valid
			if (depth.empty())
				j = i;
		}
	}
	// If depth is not zero, there is unclosed '(' at the start of the last sequence
	if (depth.empty())
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE: "<<j+1<<endl;
}
