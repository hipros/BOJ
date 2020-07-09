#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 255
#define MAXV 505

using namespace std;

struct dot {
	long long x, y;
	dot() {}
	dot(int x, int y) : x(x), y(y) {}
	unsigned int offset() {
		return x + y;
	}
};
struct hEdge {
	dot s, e;
	hEdge() {}
	hEdge(dot s, dot e): s(s.x, s.y), e(e.x, e.y) {}
};

vector<hEdge> house;
vector<dot> hole, mice;
vector<int> conn[MAXM];
bool visit[MAXV];
int mouseinhole[MAXV];

int ccw(dot a, dot b, dot c)
{
	long long t ;
	t = a.x * b.y * 1LL -a.y*b.x; t += (b.x * c.y* 1LL - b.y * c.x); t += (c.x * a.y* 1LL - c.y * a.x);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
bool cantMatch(hEdge a, hEdge b) // a : house , b : mouse & hole
{
	unsigned int A = a.s.offset(), B = a.e.offset(), C = b.s.offset(), D = b.e.offset();
	int a1 = ccw(a.s, a.e, b.s), a2 = ccw(a.s, a.e, b.e);
	int b1 = ccw(b.s, b.e, a.s), b2 = ccw(b.s, b.e, a.e);

	if (a1*a2 == -1 && !(b1*b2 == 1)) return true;
	/*if (!a1 && !a2 && !b1 && !b2) {
		if((A<C&&A<=D)^(B<C&&B<=D)) return true;
	}*/
	return false;
}
bool dfs(int m)
{
	if (visit[m]) return false;
	visit[m] = 1;
	for (int h : conn[m]) {
		if (!mouseinhole[h] || dfs(mouseinhole[h] - 1)) {
			mouseinhole[h] = m + 1;
			return true;
		}
	}
	return false;
}

int main()
{
	int N, K, H, M;
	dot input;
	scanf("%d %d %d %d", &N, &K, &H, &M); // N : house point, K : hole's afford, H : hole number, M : mice number;
	scanf("%lld %lld", &input.x, &input.y);
	house.push_back(hEdge(dot(0, 0), input));
	for (int i = 1; i < N; i++) {
		scanf("%lld %lld", &input.x, &input.y);
		house.push_back(hEdge(house[i - 1].e, input));
	}
	house.push_back(hEdge(house[N - 1].e, house[0].e));
	for (int i = 0; i < H; i++) {
		scanf("%lld %lld", &input.x, &input.y);
		hole.push_back(input);
	}
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld", &input.x, &input.y);
		mice.push_back(input);
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < H; j++) {
			int k;
			for (k = 1; k <= N; k++) {
				if (cantMatch(house[k], hEdge(mice[i], hole[j]))) break;
			}
			if (k == N + 1) {
				for (int k = 0; k < K; k++) {
					conn[i].push_back(j*K + k + M);
				}
			}
		}
	}

	int i;
	for (i = 0; i <M; i++) {
		fill(visit, visit + H * K + 2 + M, 0);
		if (!dfs(i)) break;
	}

	if (i == M) printf("Possible");
	else printf("Impossible");

	return 0;
}