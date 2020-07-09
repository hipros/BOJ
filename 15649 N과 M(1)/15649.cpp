#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ans;
bool vis[10];

void dfs(int w)
{
	if(ans.size() == M) {
		for(int a : ans) cout<<a <<' ';
		cout<<'\n';
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(vis[i]) continue;
		ans.push_back(i);
		vis[i] = 1;
		dfs(i);
		ans.pop_back();
		vis[i] = 0;
	}
}
int main ()
{
	cin>> N >>M;
	dfs(0);
	return 0;
}