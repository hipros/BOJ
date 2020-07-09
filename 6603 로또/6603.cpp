#include<bits/stdc++.h>
#define MAXN 14
using namespace std;

int N;
int seq[MAXN], num[MAXN];

void dfs(int w)
{
	if (w == 7) {
		for (int i = 1; i <= 6; i++) printf("%d ", num[seq[i]]);
		printf("\n");
		return;
	}
	for (int i = 1; seq[w - 1] + i <= N; i++) {
		seq[w] = seq[w - 1] + i;
		dfs(w + 1);
	}
}
int main()
{
	while (true) {
		scanf("%d", &N);
		if (N == 0) break;
		for (int i = 1; i <= N; i++) scanf("%d", &num[i]);
		dfs(1);
		printf("\n");
	}

	return 0;
}