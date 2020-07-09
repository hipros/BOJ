#include<bits/stdc++.h>
#define MAXN 20005
#define MOD 1000
int gp[MAXN], l[MAXN];

int find(int x)
{
	if (gp[x] == x) return x;
	int t = find(gp[x]);
	l[x] += l[gp[x]];
	return gp[x] = t;
}

void Union(int p, int q)
{
	int pp = find(p), pq = find(q);
	gp[pp] = gp[pq];
	l[pp] += l[q]; 
}
int main()
{
	char t;
	int T, N, a, b;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d\n", &N);
		for (int i = 1; i <= N; i++) gp[i] = i, l[i] = 0;
		while (true) {
			scanf("%c", &t);
			if (t == 'O') break;
			if (t == 'E') {
				scanf("%d\n", &a);
				find(a);
				printf("%d\n", l[a]);
			}
			else if (t == 'I') {
				scanf("%d %d\n", &a, &b);
				l[a] = abs(a - b) % MOD;
				Union(a, b);
			}
		}
	}

	return 0;
}