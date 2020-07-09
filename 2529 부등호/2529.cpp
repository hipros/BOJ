#include<bits/stdc++.h>
#define MAXN 10
using namespace std;

int N, number[MAXN];
bool sign[MAXN];

void func1()
{
	int num = 9;
	fill(number, number + N +1, -1);
	for (int i = 0; i < N; i++) {
		if (!sign[i]) {
			for (int j = i; j >= 0 && number[j] < 0; j--) number[j] = num--;
		}
	}
	for (int i = N; i >= 0 && number[i] < 0; i--) number[i] = num--;
	for (int i = 0; i <= N; i++) printf("%d", number[i]);
	printf("\n");
}
void func2()
{
	int num = 0;
	fill(number, number + N+1, -1);
	for (int i = 0; i < N; i++) {
		if (sign[i]) {
			for (int j = i; j >= 0 && number[j] < 0; j--) number[j] = num++;
		}
	}
	for (int i = N; i >= 0 && number[i] < 0; i--) number[i] = num++;
	for (int i = 0; i <= N; i++) printf("%d", number[i]);
	printf("\n");
}
int main()
{
	char input;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c", &input);getchar();
		sign[i] = (input == '<');
	}
	func1();
	func2();
	return 0;
}