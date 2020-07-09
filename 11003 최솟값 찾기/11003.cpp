#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000008

int num[MAXN];
deque<pair<int, int>> dq;

int main()
{
	int N, L, i;
	scanf("%d %d", &N, &L);
	for (i = 1; i <= N; i++) scanf("%d", &num[i]);
	for (i = 1; i <= N; i++) {
		while(!dq.empty() && dq.front().second <= i-L) dq.pop_front();
		while(!dq.empty() && dq.back().first > num[i]) dq.pop_back();
		dq.push_back(make_pair(num[i], i));
		printf("%d ", dq.front().first);
	}
	return 0;
}