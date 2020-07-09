#include<cstdio>
#define MAXN 10000

int main()
{
	int N, s = 0, e = -1, cnt = 0;
	int num[MAXN];
	long long M, sum = 0;
	scanf("%d %lld", &N, &M);

	for (int i = 0; i < N; ++i)
		scanf("%d", &num[i]);

	while (s != N && e < N-1) {
		sum += num[++e];
		while (sum > M && s <= e) {
			sum -= num[s++];
		}
		if (sum == M) ++cnt;
	}

	printf("%d", cnt);
	return 0;
}