#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int tree[MAXN], N, M;

void update(int w, int val)
{
	while(w <= N+M) {
		tree[w] += val;
		w += (w & -w);
	}
}
int sum(int w)
{
	int ret = 0;
	while (w) {
		ret += tree[w];
		w -= (w & -w);
	}
	return ret;
}
int main()
{
	int T, seq[MAXN];
	scanf("%d", &T);
	while (T--) {
		int pop, head;
		scanf("%d %d", &N, &M);
		memset(tree+1, 0, sizeof(int) * (N+M+1));
		for (head = 1; head <= N; head++) {
			seq[head] = N - head + 1;
			update(head, 1);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d", &pop);
			printf("%d ", sum(head-1) - sum(seq[pop]));
			update(seq[pop], -1);
			seq[pop] = head++;
			update(seq[pop], 1);
		}
		printf("\n");
	}
	return 0;
}