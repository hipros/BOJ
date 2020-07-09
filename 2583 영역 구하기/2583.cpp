#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

struct Rect {
	int sx, sy, ex, ey;

};
int N, M, K;
bool isFill[MAXN][MAXN];
Rect rect[MAXN];

int dfs(int x, int y)
{
	int ret[4] = { 0, };
	isFill[x][y] = 1;
	if (!isFill[x - 1][y] && x > 0) ret[0] = dfs(x - 1, y);
	if (!isFill[x + 1][y] && x+1 < N) ret[1] = dfs(x + 1, y);
	if (!isFill[x][y - 1] && y > 0) ret[2] = dfs(x, y - 1);
	if (!isFill[x][y + 1] && y+1 < M) ret[3] = dfs(x, y + 1);
	return ret[0] + ret[1] + ret[2] + ret[3] + 1;
}

int main()
{
	vector<int> answer;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &rect[i].sx, &rect[i].sy, &rect[i].ex, &rect[i].ey);
		for (int x = rect[i].sx; x < rect[i].ex; x++) {
			for (int y = rect[i].sy; y < rect[i].ey; y++) {
				isFill[y][x] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!isFill[i][j]) {
				answer.push_back(dfs(i, j));
			}
		}
	}
	printf("%d\n", answer.size());
	sort(answer.begin(), answer.end());
	for (unsigned int i = 0; i < answer.size(); i++) printf("%d ", answer[i]);
	return 0;
}