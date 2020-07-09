#include<bits/stdc++.h>
#define MAXN 101
using namespace std;
struct xy {
	int x, y;
	xy() {}
	xy(int x, int y) :x(x), y(y) {}
};
int N, M;
bool chee[MAXN][MAXN], state[MAXN][MAXN];
queue<xy> q;
vector<xy> meltChee[MAXN];

int airCheck()
{
	int ret = 0;
	for (int i = 0; i < M - 1; i++) {
		if (!chee[0][i]) q.push(xy(0, i)), ++ret;
		if (!chee[N - 1][i]) q.push(xy(N - 1, i)), ++ret;
	}
	for (int i = 0; i < N - 1; i++) {
		if (!chee[i][0]) q.push(xy(i, 0)), ++ret;
		if (!chee[i][M - 1]) q.push(xy(i, M - 1)), ++ret;
	}
	return ret;
}

int main()
{
	int time;
	bool cnt = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int t;
			scanf("%d", &t);
			if (t == 1) chee[i][j] = true, cnt = true;
		}
	}
	if (cnt == 0) {
		printf("0\n0");
		return 0;
	}
	for (time = 0; time== 0 ||(time != 0 && meltChee[time-1].size() != 0); time++) {
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) state[i][j] = false;
		for (xy mc : meltChee[time]) chee[mc.x][mc.y] = false;
		int air = airCheck();
		
		while (!q.empty()) {
			xy now = q.front(); q.pop();
			int x = now.x, y = now.y;
			state[x][y] = true;
			if (x > 0 && !state[x - 1][y]) {
				state[x - 1][y] = true;
				if (!chee[x - 1][y]) q.push(xy(x-1, y));
				else meltChee[time].push_back(xy(x-1, y));
			}
			if (x + 1 < N && !state[x + 1][y]) {
				state[x + 1][y] = true;
				if (!chee[x+1][y]) q.push(xy(x+1, y));
				else meltChee[time].push_back(xy(x+1, y));
			}
			if (y > 0 && !state[x][y - 1]) {
				state[x][y - 1] = true;
				if (!chee[x][y-1]) q.push(xy(x, y-1));
				else meltChee[time].push_back(xy(x, y-1));
			}
			if (y + 1 < M && !state[x][y + 1]) {
				state[x][y + 1] = true;
				if (!chee[x][y+1] ) q.push(xy(x, y+1));
				else meltChee[time].push_back(xy(x, y+1));
			}
		}
		for (xy t : meltChee[time]) chee[t.x][t.y] = false;
	}
	printf("%d\n", time-1);
	printf("%d", meltChee[time-2].size());

	return 0;
}