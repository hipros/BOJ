#include<bits/stdc++.h>
using namespace std;
vector<int> input;
set<int> ans;

int main ()
{
	int N, M;
	cin>> N >> M;
	input.resize(M+1);
	for(int i = 1; i <= M; i++) cin >> input[i];
	for(int i = 1; i <= N; i++) ans.insert(i);

	for(int i = M; i > 0; i--) {
		if(ans.find(input[i]) == ans.end()) continue;
		cout<< input[i]<<'\n';
		ans.erase(input[i]);
	}
	for(int rest : ans) cout<<rest<<'\n';
	return 0;
}