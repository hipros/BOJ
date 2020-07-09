#include<bits/stdc++.h>
#define MAXN 10005
#define INF 2147438647
using namespace std;

int fruit[MAXN], dp[MAXN], N;
vector<int> conn[MAXN];
queue<int> q;

int maxFruits(int s)
{
	int maxi = 0;
	q.push(s); dp[s] = fruit[s];

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : conn[now]) {
			if (dp[next] < INF) continue;
			q.push(next);
			dp[next] = dp[now] + fruit[next];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (maxi == 0 || dp[maxi] < dp[i]) {
			maxi = i;
		}
	}
	return maxi;
}
int main()
{
	int n1, n2, end;
	int answerv = 0, answernode;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &fruit[i]);

	for (int i = 1; i < N; i++) {
		scanf("%d %d", &n1, &n2);
		conn[n1].push_back(n2);
		conn[n2].push_back(n1);
	}

	for(int i = 1;i <= N; i++) dp[i] = INF;
	end = maxFruits(1);
	for(int i = 1;i <= N; i++) dp[i] = INF;
	answernode = maxFruits(end);
	printf("%d %d", dp[answernode], (end > answernode)?answernode:end);

	return 0;
}