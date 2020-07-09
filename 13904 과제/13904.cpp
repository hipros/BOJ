#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

struct work{
	int dead;
	int val;
}hw[MAXN];
bool operator<(const work& a, const work& b)
{
	return a.val < b.val;
}
priority_queue<work> pq;

int main ()
{
	int N, i, max_dead, answer = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) scanf("%d %d", &hw[i].dead, &hw[i].val);
	sort(hw, hw+N, [](const work& a, const work& b){
		return a.dead > b.dead;
	});
	i = 0;
	for(max_dead = hw[0].dead; max_dead>= 1; max_dead--){
		while(i < N && hw[i].dead >= max_dead) pq.push(hw[i++]);
		if(!pq.empty()) {
			answer += pq.top().val;
			pq.pop();
		}
	}
	printf("%d", answer);
	return 0;
}