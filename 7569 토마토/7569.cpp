#include<bits/stdc++.h>
#define MAXN 101
using namespace std;

struct xyz {
	int x, y, z;
	xyz() {}
	xyz(int z, int x, int y) :x(x), y(y), z(z) {}
};
int MAP[MAXN][MAXN][MAXN];
int state[MAXN][MAXN][MAXN];
vector<xyz> v;
queue<xyz> q;
int main()
{
	xyz now = xyz(0, 0, 0);
	int M, N, H, cnt = 0;
	scanf("%d %d %d", &M, &N, &H);
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &MAP[k][i][j]);
				if (MAP[k][i][j] == 1) v.push_back(xyz(k, i, j));
				else if (MAP[k][i][j] == 0) cnt++;
			}
		}
	}
	if(cnt == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < v.size(); i++)
		q.push(v[i]);

	while (!q.empty() && cnt > 0) {
		now = q.front(); q.pop();
		int x = now.x, y = now.y, z = now.z;
		if (z>0 && !state[z - 1][x][y] && MAP[z - 1][x][y] == 0) {
			state[z - 1][x][y] = state[z][x][y] + 1;
			q.push(xyz(z - 1, x, y));
			cnt--;
		}
		if (z + 1<H && !state[z + 1][x][y] && MAP[z + 1][x][y] == 0) {
			state[z + 1][x][y] = state[z][x][y] + 1;
			q.push(xyz(z + 1, x, y));
			cnt--;
		}
		if (x>0 && !state[z][x - 1][y] && MAP[z][x - 1][y] == 0) {
			state[z][x - 1][y] = state[z][x][y] + 1;
			q.push(xyz(z, x - 1, y));
			cnt--;
		}
		if (x + 1<N && !state[z][x + 1][y] && MAP[z][x + 1][y] == 0) {
			state[z][x + 1][y] = state[z][x][y] + 1;
			q.push(xyz(z, x + 1, y));
			cnt--;
		}
		if (y>0 && !state[z][x][y - 1] && MAP[z][x][y - 1] == 0) {
			state[z][x][y - 1] = state[z][x][y] + 1;
			q.push(xyz(z, x, y - 1));
			cnt--;
		}
		if (y + 1<M && !state[z][x][y + 1] && MAP[z][x][y + 1] == 0) {
			state[z][x][y + 1] = state[z][x][y] + 1;
			q.push(xyz(z, x, y + 1));
			cnt--;
		}
	}
	if (cnt != 0) printf("-1");
	else printf("%d", state[now.z][now.x][now.y]+1);
	getchar(); getchar();
	return 0;
}