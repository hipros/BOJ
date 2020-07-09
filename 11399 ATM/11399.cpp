#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

int main ()
{
	int N, num[MAXN];
	long long answer = 0;
	scanf("%d", &N);
	for(int i = 1;i <= N; i++) scanf("%d", &num[i]);

	sort(num+1, num+N+1, [] (int a, int b) {
		return a > b;
	});

	for(int i = 1;i <= N; i++) answer += (num[i]*i);
	printf("%lld", answer);

	return 0;
}