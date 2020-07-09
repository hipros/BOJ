#include<bits/stdc++.h>
#define MAXN 101
#define MAXM 14
#define INF (100*100+1)
#define x first
#define y second
using namespace std;
int N, M;
bool chickChoice[MAXM];
int dist[MAXM][MAXN];
int answer;
vector<pair<int, int> > chicken, house;

int distance(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int findLen()
{
	int Cdist[MAXN] = {0, }, ret = 0;
	for (unsigned int i = 0; i < house.size(); i++) Cdist[i] = INF;
	for (int i = 0; i < chicken.size(); i++) {
		if (!chickChoice[i]) continue;
		for (int j = 0; j < house.size(); j++) Cdist[j] = min(Cdist[j], dist[i][j]);
	}
	for (unsigned int i = 0; i < house.size(); i++) ret += Cdist[i];
	return ret;
}

bool combiChicken(int seq, int many)
{
	unsigned int i;
	if (many <= M) answer = min(answer, findLen());
	else if (seq != -1 && chicken.size() - seq - 1 < M - many) return false;
	for (i = seq + 1; i < chicken.size(); i++) {
		chickChoice[i] = true;
		if (!combiChicken(i, many + 1)) break;
		chickChoice[i] = false;
	}
	return true;
}

int main()
{
	int input;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &input);
			if (input == 2) chicken.push_back(make_pair(i, j));
			else if (input == 1) house.push_back(make_pair(i, j));
		}
	}
	for (unsigned int i = 0; i < chicken.size(); i++) {
		for (unsigned int j = 0; j < house.size(); j++) {
			dist[i][j] = distance(chicken[i].x, chicken[i].y, house[j].x, house[j].y);
		}
	}
	answer = INF;
	combiChicken(-1, 0);
	printf("%d", answer);

	return 0;
}