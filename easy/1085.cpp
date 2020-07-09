#include<cstdio>
#include<algorithm>

using namespace std;

int main ()
{
	int a, b,c,d, answer;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	answer = min(a, b);
	answer = min(answer, abs(a-c));
	answer = min(answer, abs(b-d));
	printf("%d\n", answer);	
	return 0;
}