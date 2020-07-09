#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ans, num;
bool vis[10];

void dfs(int w)
{
	if(ans.size() == M) {
		for(int a : ans) cout<<a <<' ';
		cout<<'\n';
		return;
	}
	for(int i = 0; i < N; i++) {
		if(vis[i]) continue;
		ans.push_back(num[i]);
		vis[i] = 1;
		dfs(i);
		ans.pop_back();
		vis[i] = 0;
	}
}
int main ()
{
	cin>> N >>M;
	num.resize(N);
	for(int i = 0; i <N; i++) cin>>num[i];
	sort(num.begin(), num.end());
	dfs(0);
	return 0;
}