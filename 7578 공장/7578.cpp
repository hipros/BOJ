#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int tree[MAXN], N, seq[MAXN];
int order1[MAXN], order2[MAXN];
pair<int, int> order3[MAXN];

int findsum(int w)
{
	int ret = 0;
	while (w) {
		ret += tree[w];
		w -= (w & -w);
	}
	return ret;
}
void update(int w)
{
	while (w <= N) {
		tree[w] += 1;
		w += (w & -w);
	}
}
void input(int *order)
{
	for (int i = 1; i <= N; i++) {
		scanf("%d", &seq[i]);
		order[i] = i;
	}
	sort(order + 1, order + N + 1, [](const int &a,const int &b) {
		return seq[a] < seq[b];
	});
}
int main()
{
	long long answer = 0;
	scanf("%d", &N);
	input(order1);
	input(order2);
	for (int i = 1; i <= N; i++) order3[i] = make_pair(order1[i], order2[i]);
	sort(order3 + 1, order3 + N + 1);
	for (int i = 1; i <= N; i++) {
		answer += findsum(N) - findsum(order3[i].second-1);
		update(order3[i].second);
	}
	printf("%lld\n", answer);
	return 0;
}