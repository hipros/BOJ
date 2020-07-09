#include<bits/stdc++.h>
#define MAXN 300005

int gp[MAXN];
bool full[MAXN];

int find(int x)
{
	if (gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
void Union(int p, int q)
{
	int pp = find(p), pq = find(q);
	if (!full[pp]) gp[pq] = gp[pp];
	else gp[pp] = gp[pq];
}
int main()
{
	int N, L, l1, l2, pl1, pl2, check;
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= L; i++) gp[i] = i;
	for (int i = 0; i < N; i++) {
		check = 0;
		scanf("%d %d", &l1, &l2);
		pl1 = find(l1); pl2 = find(l2);
		if (!full[l1]) full[l1] ^= 1;
		else if (!full[l2]) full[l2] ^= 1;
		else if (!full[pl1]) full[pl1] ^= 1;
		else if (!full[pl2]) full[pl2] ^= 1;
		else {
			printf("SMECE\n");
			check ^= 1;
		}
		if (check == 0) {
			printf("LADICA\n");
			Union(pl1, pl2);
		}
	}
	return 0;
}