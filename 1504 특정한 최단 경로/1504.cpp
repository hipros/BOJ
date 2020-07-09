#include<bits/stdc++.h>
#define INF (int)1e9
#define MAXN 805
using namespace std;
struct Edge {
	int e, val;
	Edge() {}
	Edge(int e, int val) : e(e), val(val) {}
};

vector<Edge> conn[MAXN];
int dist[MAXN], N;

int dijk(int s, int e)
{
	bool visit[MAXN];
	for (int i = 1; i <= N; i++) dist[i] = INF, visit[i] = false;
	dist[s] = 0;

	for (int i = 1; i <= N; i++) {
		int mini = 0;
		for (int i = 1; i <= N; i++) {
			if ((mini == 0||dist[i] < dist[mini]) && !visit[i]) mini = i;
		}
		visit[mini] = true;
		for (Edge next : conn[mini]) {
			if (visit[next.e]) continue;
			if (dist[next.e] > dist[mini] + next.val) {
				dist[next.e] = dist[mini] + next.val;
			}
		}
	}
	return dist[e];
}
int main()
{
	int E, a, b;
	long long  answer = 0;
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		int s, e, v;
		scanf("%d %d %d", &s, &e, &v);
		conn[s].push_back(Edge(e, v));
		conn[e].push_back(Edge(s, v));
	}
	scanf("%d %d", &a, &b);

	answer = 0LL + dijk(1, a) + dijk(a, b) + dijk(b, N);
	answer = min(answer, 0LL + dijk(1, b) + dijk(b, a) + dijk(a, N));

	if (answer >= INF) printf("-1");
	else printf("%lld", answer);
	return 0;
}