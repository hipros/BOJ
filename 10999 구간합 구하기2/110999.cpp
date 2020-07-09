
#include<bits/stdc++.h>
#define ll long long
#define MAXN 1048580
using namespace std;
ll tree[MAXN * 2], num[MAXN], lazy[MAXN * 2];

ll init(int w, int begin, int end)
{
	if (begin == end) return tree[w] = num[begin];
	int mid = (begin + end) / 2;
	return tree[w] = init(w * 2, begin, mid) + init(w * 2 + 1, mid + 1, end);
}
void lazy_update(int w, int begin, int end)
{
	if (lazy[w]) {
		tree[w] += (end - begin + 1) * lazy[w];
		if (begin < end) {
			lazy[w * 2] += lazy[w];
			lazy[w * 2 + 1] += lazy[w];
		}
		lazy[w] = 0;
	}
}
void update_range(int w, int left, int right, int begin, int end, ll diff)
{
	lazy_update(w, begin, end);
	if (begin > right || end < left) return;
	if (begin >= left && end <= right) {
		tree[w] += (end - begin + 1) * diff;
		if (begin < end) {
			lazy[w * 2] += diff;
			lazy[w * 2 + 1] += diff;
		}
		return;
	}
	int mid = (begin + end) / 2;
	update_range(w * 2, left, right, begin, mid, diff);
	update_range(w * 2 + 1, left, right, mid + 1, end, diff);
	tree[w] = tree[w * 2] + tree[w * 2 + 1];
}
ll sum(int w, int left, int right, int begin, int end)
{
	lazy_update(w, begin, end);
	if (begin > right || end < left) return 0;
	if (left <= begin && right >= end) {
		return tree[w];
	}
	int mid = (begin + end) / 2;
	return sum(w * 2, left, right, begin, mid) + sum(w * 2 + 1, left, right, mid + 1, end);
}

int main()
{
	ll d;
	int N, M, K, k, a, b, c;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &num[i]);
	for (k = 1; k < N; k = (k<<1)); N = k;
	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %lld", &b, &c, &d);
			update_range(1, b, c, 1, N, d);
		}
		else if (a == 2) {
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, b, c, 1, N));
		}
	}
	return 0;
}