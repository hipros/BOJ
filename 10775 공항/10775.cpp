#include<bits/stdc++.h>
#define MAXN 100005
int gp[MAXN];
int find(int x)
{
	if (gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
void Union(int p, int q)
{
	gp[find(p)] = gp[find(q)];
}
int main()
{
	int G, P, g, w, cnt = 0;
	scanf("%d %d", &G, &P);
	for (int i = 1; i <= G; i++) gp[i] = i;
	for (cnt = 0; cnt < P; cnt++) {
		scanf("%d", &g);
		w = find(g);
		if (w == 0) break;
		Union(w, w - 1);
	}
	printf("%d", cnt);

	return 0;
}