#include<cstdio>
#include<iostream>
using namespace std;

long long N, k;
int sz;
pair<int, int> w[4] = { {0,0},{-1, 0},{-1, 1},{0, 1}};

void walk(long long n, long long x, long long y, long long k, int depth)
{
	long long t , w1, w2;
	if (depth == sz) {
		printf("%lld %lld ", y+1, N-x);
		return;
	}
	t = k / ((n / 2)*(n / 2)); w1 = w[t].first * (n / 2); w2 = w[t].second * (n / 2);
	if(t == 0 || t == 3) swap(w[(t+1)%4], w[(t+3)%4]);

	walk(n / 2, x + w1, y + w2, k % ((n/2)*(n/2)), depth+1);
}

int main()
{
	long long temp;
	scanf("%lld %lld", &N, &k);
	temp = N;
	while ((temp >>= 1)) ++sz;

	walk(N, N - 1, 0, k - 1, 0);
	return 0;
}