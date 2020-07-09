#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50005;

struct cow{ int h, x; };
bool operator<(cow a, cow b) { return a.h < b.h; }

cow c[MAXN];
priority_queue<cow> pq;

int main ()
{
	bool blockl[MAXN], blockr[MAXN];
	int N, D, answer = 0;
	cin>> N >> D;
	for(int i = 0; i < N; i++) cin>> c[i].x>> c[i].h;

	sort(c, c+N, [](const cow& a, const cow& b){
		return a.x < b.x;
	});

	for(int i = 0; i < N; i++){
		cow hg;
		pq.push(c[i]);
		while (pq.top().x < c[i].x - D) pq.pop();
		hg = pq.top();
		if(hg.h >= c[i].h*2) blockl[i]++;
	}
	while(!pq.empty()) pq.pop();

	for(int i = N-1; i >= 0; i--){
		cow hg;
		pq.push(c[i]);
		while(pq.top().x > c[i].x + D) pq.pop();
		hg = pq.top();
		if(hg.h >= c[i].h*2) blockr[i]++;
	}

	for(int i= 0; i < N; i++) if(blockr[i] && blockl[i]) answer++;
	cout<< answer;
	return 0;
}