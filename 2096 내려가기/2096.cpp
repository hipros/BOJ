#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

int main()
{
	int N, maxdp[2][5] = { 0, }, mindp[2][5] = { 0, }, input[5];
	int answer[2] = {0,INF};
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) scanf("%d", &input[j]);
		for(int j = 1;j <= 3; j++) {
			mindp[i%2][j] = INF;
			if(j != 1) maxdp[i%2][j] = max(maxdp[i%2][j], maxdp[(i%2)^1][j-1] + input[j]);
			maxdp[i%2][j] = max(maxdp[i%2][j], maxdp[(i%2)^1][j] + input[j]);
			if(j != 3) maxdp[i%2][j] = max(maxdp[i%2][j], maxdp[(i%2)^1][j+1] + input[j]);
			if(j != 1) mindp[i%2][j] = min(mindp[i%2][j], mindp[(i%2)^1][j-1] + input[j]);
			mindp[i%2][j] = min(mindp[i%2][j], mindp[(i%2)^1][j] + input[j]);
			if(j != 3) mindp[i%2][j] = min(mindp[i%2][j], mindp[(i%2)^1][j+1] + input[j]);
		}
	}
	for (int j = 1; j <= 3; j++) {
		answer[0] = max(answer[0], maxdp[N % 2][j]);
		answer[1] = min(answer[1], mindp[N % 2][j]);
	}
	printf("%d %d\n", answer[0], answer[1]);

	return 0;
}
