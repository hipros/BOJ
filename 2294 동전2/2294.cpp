#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int N, K, V[101], dp[10001];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> V[i];

	sort(V, V + N);
	fill(dp, dp + K + 1, INF);
	dp[0] = 0;

	for (int i = 1; i <= K; i++){
		for (int j = 0; j < N && i >= V[j]; j++){
			dp[i] = min(dp[i], dp[i - V[j]] + 1);
		}
	}

	if (dp[K] < INF) cout << dp[K];
	else cout << -1;
	return 0;
}