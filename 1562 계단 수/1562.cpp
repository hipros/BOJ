#include<bits/stdc++.h>
#define MOD 1000000000
long long stair[2][(1 << 10)][10], answer;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i < 10; i++) stair[1][(1 << i)][i] = 1;
	for (int i = 1; i < N; i++) { // N
		for (int j = 1; j <= (1 << 10) - 1; j++) { //toggle check
			for (int k = 0; k < 10; k++) { //new number
				if (!stair[i % 2][j][k]) continue;
				if (k) stair[(i % 2) ^ 1][j | (1 << (k-1))][k - 1] += stair[i % 2][j][k], stair[(i % 2) ^ 1][j | (1 << (k-1))][k - 1] %= MOD;
				if (k < 9) stair[(i % 2) ^ 1][j | (1 << (k+1))][k + 1] += stair[i % 2][j][k], stair[(i % 2) ^ 1][j | (1 << (k+1))][k + 1] %= MOD;
				stair[i % 2][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < 10; i++) answer += stair[N % 2][(1 << 10) - 1][i], answer %= MOD;
	printf("%lld\n", answer);

	return 0;
}