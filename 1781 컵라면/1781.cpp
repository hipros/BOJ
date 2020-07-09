#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct pro{ 
	int deadline, reward; 
}p[MAXN];
priority_queue<int> pq;

int main ()
{
	int N, i;
	int answer = 0;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d %d", &p[i].deadline, &p[i].reward);
	sort(p+1, p+N+1, [](const pro& a,const pro& b){
		return a.deadline > b.deadline;
	});
	for(int dtime = N, i = 1; dtime > 0; dtime--) {
		while(i <= N && dtime <= p[i].deadline) pq.push(p[i].reward), i++;
		if(!pq.empty()) answer += pq.top(), pq.pop();
	}
	printf("%d", answer);
	return 0;
}