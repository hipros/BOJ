#include<bits/stdc++.h>
#define ll long long

int main()
{
	int n;
	ll fibo[2] = { 0,1 };
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) fibo[i % 2] = fibo[0] + fibo[1];
	printf("%lld", fibo[n%2]);
	return 0;
}