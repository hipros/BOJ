#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1e5) + 5;
vector<int> n[MAXN];
int order[MAXN], dp[MAXN];
bool vis[MAXN];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, answer = 0;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		n[a].push_back(b);
		n[b].push_back(a);
	}
	for(int i = 0; i < N; i++) order[i] = i;
	sort(order, order+N, [](const int& a, const int& b) {
		return n[a].size() < n[b].size();
	});
	for(int i = 0; i < N; i++) {
		int now = order[i];
		dp[now] = max(dp[now], 1);
		for(int next : n[now]) {
			if(n[now].size() > n[next].size()) dp[now] = max(dp[now], dp[next]+1);
		}
	}
	for(int i = 0; i < N; i++) answer = max(answer, dp[i]);
	cout<< answer<<'\n';
	return 0;
}