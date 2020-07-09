#include<bits/stdc++.h>
#define MAXL 100005
using namespace std;

int TIME[MAXL];

int main ()
{
	int N, K;
	queue<int> q;
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= MAXL; i++) TIME[i] = MAXL*2;
	q.push(N); TIME[N] = 0;

	while(!q.empty()) {
		int now = q.front(); q.pop();
		if(now > 0 && TIME[now-1] > TIME[now]+1) {
			q.push(now-1);
			TIME[now-1] = TIME[now]+1;
		}
		if(now *2 <= 100000&& TIME[now*2] > TIME[now]+1 && now < K) {
			q.push(now*2);
			TIME[now*2] = TIME[now]+1;
		}
		if(now < 100000&& TIME[now+1] > TIME[now]+1) {
			q.push(now+1);
			TIME[now+1] = TIME[now]+1;
		}
	}
	printf("%d\n", TIME[K]);
	return 0;
}