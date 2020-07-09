#include<bits/stdc++.h>

int main()
{
	int C, answer = 0;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	scanf("%d", &C);
	C = 1000 - C;
	for (int i = 0; i < 6 && C; i++) {
		answer += (C / coin[i]);
		C = (C%coin[i]);
	}
	printf("%d", answer);
	return 0;
}