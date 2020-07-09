#include<cstdio>

int main ()
{
	int n = 64, input, answer = 0;
	scanf("%d", &input);
	while(input) {
		while(n > input) n /= 2;
		input -= n;
		++answer;
	}
	printf("%d", answer);
	return 0;
}