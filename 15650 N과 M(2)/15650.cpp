#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ans;

void dfs(int w)
{
	if(ans.size() == M) {
		for(int a : ans) cout<<a <<' ';
		cout<<'\n';
		return;
	}
	for(int i = w+1; i <= N; i++) {
		ans.push_back(i);
		dfs(i);
		ans.pop_back();
	}
}
int main ()
{
	cin>> N >>M;
	dfs(0);
	return 0;
}