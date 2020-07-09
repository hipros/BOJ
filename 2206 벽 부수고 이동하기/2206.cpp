#include<bits/stdc++.h>
#define MAXN 1005
#define INF (int)1e7
using namespace std;
struct xy {
	int layer;
	int x;
	int y;
	xy() {}
	xy(int layer, int x, int y): layer(layer), x(x), y(y) {}
};
int state[2][MAXN][MAXN];
bool MAP[MAXN][MAXN];
queue<xy> q;

int main()
{
	char input;
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &input);
			MAP[i][j] = input - '0';
		}
		getchar();
	}
	state[0][0][0] = 1;
	q.push(xy(0, 0, 0));
	while (!q.empty()) {
		if (state[0][N - 1][M - 1] || state[1][N - 1][M - 1]) break;
		xy now = q.front(); q.pop();
		if (now.x > 0) {
			if (state[now.layer][now.x - 1][now.y] == 0 && MAP[now.x - 1][now.y] == 0) state[now.layer][now.x - 1][now.y] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer, now.x - 1, now.y));
			if (state[1][now.x - 1][now.y] == 0 && MAP[now.x - 1][now.y] == 1 && now.layer == 0) state[now.layer + 1][now.x - 1][now.y] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer + 1, now.x - 1, now.y));
		}
		if (now.x + 1 < N) {
			if (state[now.layer][now.x + 1][now.y] == 0 && MAP[now.x + 1][now.y] == 0) state[now.layer][now.x + 1][now.y] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer, now.x + 1, now.y));
			if (state[1][now.x + 1][now.y] == 0 && MAP[now.x + 1][now.y] == 1 && now.layer == 0) state[now.layer + 1][now.x + 1][now.y] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer + 1, now.x + 1, now.y));
		}
		if (now.y > 0) {
			if (state[now.layer][now.x][now.y - 1] == 0 && MAP[now.x][now.y - 1] == 0) state[now.layer][now.x][now.y - 1] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer, now.x, now.y - 1));
			if (state[1][now.x][now.y - 1] == 0 && MAP[now.x][now.y - 1] == 1 && now.layer == 0) state[now.layer + 1][now.x][now.y - 1] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer + 1, now.x, now.y - 1));
		}
		if (now.y + 1 < M) {
			if (state[now.layer][now.x][now.y + 1] == 0 && MAP[now.x][now.y + 1] == 0) state[now.layer][now.x][now.y + 1] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer, now.x, now.y + 1));
			if (state[1][now.x][now.y + 1] == 0 && MAP[now.x][now.y + 1] == 1 && now.layer == 0) state[now.layer + 1][now.x][now.y + 1] = state[now.layer][now.x][now.y] + 1, q.push(xy(now.layer + 1, now.x, now.y + 1));
		}
	}
	if (q.empty()) printf("-1");
	else printf("%d", max(state[0][N - 1][M - 1], state[1][N - 1][M - 1]));

	return 0;
}