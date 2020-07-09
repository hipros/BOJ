#include<cstdio>

int decomposesum(int num)
{
	int sum = 0;
	while(num != 0){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main ()
{
	int n, i, answer = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		if(n == i+ decomposesum(i)){
			answer = i;
			break;
		}
	}
	printf("%d", answer);
	return 0;
}