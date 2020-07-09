#include<bits/stdc++.h>
using namespace std;

struct App {
	int mem;
	int cost;
};
int dp[100][10001];

int main()
{
	int N, M, answer, i, j;
	App app[100];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d", &app[i].mem);
	for (i = 0; i < N; i++)
		scanf("%d", &app[i].cost);

	for (i = 0; i <= 10000; i++) {
		for (j = 0; j < N; j++) {
			if (app[j].cost == i) dp[j][i] = app[j].mem;
			if (app[j].cost > i) continue;
			
			for (int k = 0; k < j; k++) {
				dp[j][i] = max(dp[j][i], dp[k][i - app[j].cost] + app[j].mem);
			}

			if (dp[j][i] >= M) {
				answer = i;
				break;
			}
		}
		if (j != N) break;
	}
	printf("%d", answer);
	return 0;
}
