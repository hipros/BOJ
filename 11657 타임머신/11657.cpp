#include<bits/stdc++.h>
#define INF 2e9
#define MAXN 501
using namespace std;

struct Edge {
	int s;
	int e;
	int val;
};

int dist[MAXN];
vector<Edge> edge;

int main()
{
	const int inf = (int)INF;
	Edge t;
	int N, M;
	bool cycleExist = false;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t.s, &t.e, &t.val);
		edge.push_back(t);
		if (dist[1] == inf && t.s == 1) dist[1] = 0;
	}
	fill(dist + 2, dist + N + 2, inf);

	for (int i = 0; i < N; i++) {
		for (Edge ed : edge) {
			if (dist[ed.e] > dist[ed.s] + ed.val && dist[ed.s] < inf) {
				dist[ed.e] = dist[ed.s] + ed.val;
				if (i == N - 1) cycleExist = true;
			}
		}
	}
	if (cycleExist && dist[1] < inf)
		printf("-1");
	else
		for (int i = 2; i <= N; i++) printf("%d\n", (dist[i] == inf) ? -1 : dist[i]);

	return 0;
}