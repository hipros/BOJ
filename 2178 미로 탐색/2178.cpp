#include<bits/stdc++.h>
#define MAXN 101
#define INF (int)2e5
using namespace std;

bool MAP[MAXN][MAXN];
int depth[MAXN][MAXN];

struct xy {
	int x, y;
	int length;
	xy() {}
	xy(int x, int y, int length) : x(x), y(y), length(length) {}
};

int main()
{
	queue<xy> q;
	int N, M, answer;
	char c;
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &c);
			if (c == '1') MAP[i][j] = true;
			depth[i][j] = INF;
		}
		getchar();
	}

	q.push(xy(0, 0, 1)); depth[0][0] = 1;

	while (true) {
		xy now = q.front(); q.pop();
		if (now.x == N - 1 && now.y == M - 1) {
			answer = now.length;
			break;
		}
		if (now.x > 0 && MAP[now.x-1][now.y] && now.length + 1 < depth[now.x - 1][now.y]) {
			depth[now.x - 1][now.y] = now.length + 1;
			q.push(xy(now.x - 1, now.y, now.length + 1));
		}
		if (now.x+1 < N && MAP[now.x+1][now.y] && now.length + 1 < depth[now.x + 1][now.y]) {
			depth[now.x + 1][now.y] = now.length + 1;
			q.push(xy(now.x + 1, now.y, now.length + 1));
		}
		if (now.y > 0 && MAP[now.x][now.y-1] && now.length + 1 < depth[now.x][now.y - 1]) {
			depth[now.x][now.y-1] = now.length + 1;
			q.push(xy(now.x, now.y - 1, now.length + 1));
		}
		if (now.y + 1 < M && MAP[now.x][now.y+1] && now.length + 1 < depth[now.x][now.y + 1]) {
			depth[now.x][now.y + 1] = now.length + 1;
			q.push(xy(now.x, now.y + 1, now.length + 1));
		}
	}
	printf("%d", answer);
	return 0;
}