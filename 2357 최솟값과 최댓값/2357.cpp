#include<bits/stdc++.h>
#define MAXN ((1<<17)+5)
#define INF 1000000000
using namespace std;
int maxtree[MAXN * 2], num[MAXN], mintree[MAXN * 2];

int minInit(int w, int begin, int end)
{
	if (begin == end) return mintree[w] = (num[begin]) ? num[begin] : INF;
	int mid = (begin + end) / 2;
	return mintree[w] = min(minInit(w * 2, begin, mid), minInit(w * 2 + 1, mid + 1, end));
}
int maxInit(int w, int begin, int end)
{
	if (begin == end) return maxtree[w] = num[begin];
	int mid = (begin + end) / 2;
	return maxtree[w] = max(maxInit(w * 2, begin, mid), maxInit(w * 2 + 1, mid + 1, end));
}
int maxFind(int w, int begin, int end, int left, int right)
{
	if (begin > right || end < left) return 0;
	if (begin >= left && end <= right) return maxtree[w];
	int mid = (begin + end) / 2;
	return max(maxFind(w * 2, begin, mid, left, right), maxFind(w * 2 + 1, mid+1, end, left, right));
}
int minFind(int w, int begin, int end, int left, int right)
{
	if (begin > right || end < left) return INF;
	if (begin >= left && end <= right) return mintree[w];
	int mid = (begin + end) / 2;
	return min(minFind(w * 2, begin, mid, left, right), minFind(w * 2 + 1, mid+1, end, left, right));
}
int main()
{
	int N, M, k, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", &num[i]);
	for (k = 1; k < N; k = (k << 1)); N = k;
	minInit(1, 1, N); maxInit(1, 1, N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", minFind(1, 1, N, a, b), maxFind(1, 1, N, a, b));
	}

	return 0;
}