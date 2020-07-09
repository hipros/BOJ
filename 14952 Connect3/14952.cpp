#include<bits/stdc++.h>
using namespace std;
const int MAXP = (int)5e7, MAXN = 4;

int X, A, B, answer;
int thr[16];
bool visit[MAXP];
char m[MAXN][MAXN], y[MAXN];
int chw[4][2] = {{1, 0}, {0, 1}, {1, 1}, {-1, 1}};

inline int trXY2N(int x, int y) { return x * MAXN + y; }
inline bool isin(int x, int y) { return x >= 0 && y >= 0 && x < MAXN && y < MAXN; }

bool check()
{
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (m[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int cnt = 0, ni = i, nj = j;
					for (; cnt < 2; cnt++){
						ni += chw[k][0];
						nj += chw[k][1];

						if (!isin(ni, nj) || m[i][j] != m[ni][nj]) break;
					}
					if (cnt == 2) return true;
				}
			}
		}
	}
	return false;
}

void dfs(bool bw, int state)
{
	visit[state] = 1;
	for (int i = 0; i < MAXN; i++) {
		int nextst = state + thr[trXY2N(y[i], i)] * (bw + 1);
		if (y[i] < MAXN && !visit[nextst]) {
			m[y[i]][i] = (bw + 1);
			if (check()){
				if (y[i] == A && i == B && bw == 0) {
					answer++;
				}
			}
			else if (!(y[i] == A && i == B)) {
				y[i]++;
				dfs(bw ^ 1, nextst);
				y[i]--;
			}
			m[y[i]][i] = 0;
		}
	}
}

int main()
{
	int st = 0;
	cin >> X;
	cin >> A >> B;
	--A; --B; --X;
	thr[0] = 1;
	for (int i = 1; i < 16; i++) thr[i] = thr[i - 1] * 3;
	m[0][X] = 2; y[X] = 1;
	st = 0 + thr[trXY2N(0, X)] * 2;
	dfs(0, st);
	cout << answer;
	return 0;
}