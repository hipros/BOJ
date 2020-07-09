#include<bits/stdc++.h>
#define MAXN 10005
int gp[MAXN], cost[MAXN];

int find(int x)
{
	if (gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
void Union(int p, int q)
{
	int pp = find(p), pq = find(q);
	if (cost[pp] < cost[pq]) gp[pq] = gp[pp];
	else gp[pp] = gp[pq];
}
int main()
{
	int N, M, K, s, e, mkfrcost = 0;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%d", &cost[i]), gp[i] = i;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		Union(s, e);
	}
	for (int i = 1; i <= N; i++)	if (gp[i] == i) mkfrcost += cost[i];

	if (mkfrcost <= K) printf("%d", mkfrcost);
	else printf("Oh no");
	return 0;
}