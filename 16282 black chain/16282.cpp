#include<bits/stdc++.h>

unsigned long long calc(unsigned long long n)
{
	unsigned long long p = pow(2.0, n + 1);
	return n + (n+1)*(unsigned long long)(p - 1);
}

int main()
{
	unsigned long long N;
	scanf("%lld", &N);

	for (int i = 1;; i++) {
		if (N <= calc(i)) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}