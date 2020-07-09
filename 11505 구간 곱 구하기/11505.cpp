#include<bits/stdc++.h>
#define MAXN (1<<20)
#define ll long long
#define MOD 1000000007
using namespace std;
ll num[MAXN], tree[MAXN*2];

ll init(int w, int begin, int end)
{
	if (begin == end) return tree[w] = num[begin];
	int mid = (begin + end) / 2;
	return tree[w] = (init(w * 2, begin, mid) * init(w * 2 + 1, mid + 1, end)) % MOD;
}
void update(int w, int begin, int end, int chw, int val)
{
	if (begin > chw || end < chw) return;
	if (begin == end) {
		if (begin == chw) tree[w] = val;
		return;
	}
	int mid = (begin + end) / 2;
	update(w * 2, begin, mid, chw, val);
	update(w * 2 + 1, mid + 1, end, chw, val);
	tree[w] = (tree[w * 2] * tree[w * 2 + 1])%MOD;
	return;
}
ll mul(int w, int begin, int end, int left, int right)
{
	if (begin > right || end < left) return 1;
	if (begin >= left && end <= right) return tree[w];
	int mid = (begin + end) / 2;
	return (mul(w * 2, begin, mid, left, right) * mul(w * 2 + 1, mid + 1, end, left, right))%MOD;
}

int main()
{
	int N, M, K, a, b, c, k;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &num[i]);
	for (k = 1; k < N; k = (k << 1));
	for (int i = N + 1; i <= k; i++) num[i] = 1;
	N = k;
	init(1, 1, N);
	for (int i = 1; i <= M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { //update
			update(1, 1, N, b, c);
			num[b] = c;
		}
		else if (a == 2) { //구간 곱
			printf("%lld\n", mul(1, 1, N, b, c));
		}
	}
	return 0;
}