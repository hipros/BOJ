#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 500

using namespace std;

int time[MAXN + 1], build[MAXN + 1], indeg[MAXN+1];
vector<int> conn[MAXN + 1];
int N;
priority_queue<int> q;

int main()
{
	int input = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &time[i]);
		while (true) {
			scanf("%d", &input);
			if (input == -1) break;
			conn[input].push_back(i);
			indeg[i]++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			build[i] = time[i];
		}
	}
	while (!q.empty()) {
		int node = q.top(); q.pop();
		for (int t : conn[node]) {
			indeg[t]--;
			if (indeg[t] == 0) q.push(t);
			build[t] = max(build[t], build[node] + time[t]);
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", build[i]);
	system("pause");
	return 0;
}