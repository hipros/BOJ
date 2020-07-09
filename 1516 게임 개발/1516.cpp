#include<bits/stdc++.h>
#define MAXN 505
using namespace std;

int main ()
{
	int N, t[MAXN], indg[MAXN], time[MAXN];
	queue<int> q;
	vector<int> conn[MAXN];
	scanf("%d", &N);
	fill(time+1, time+N+2, 0);
	fill(indg+1, indg+N+2, 0);
	for(int i = 1; i <= N; i++) {
		int input;
		scanf("%d", &t[i]);
		for(;;){
			scanf("%d", &input);
			if(input == -1) break;
			conn[input].push_back(i);
			indg[i]++;
		}
	}
	for(int i = 1; i <= N; i++) if(indg[i] == 0) q.push(i), time[i] = t[i];
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(int next : conn[now]) {
			indg[next]--;
			time[next] = max(time[next], time[now]);
			if(indg[next] == 0) q.push(next), time[next] += t[next];
		}
	}
	for(int i = 1; i <= N; i++) printf("%d\n", time[i]);
	return 0;
}