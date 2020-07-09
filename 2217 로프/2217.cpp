#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int rope[MAXN];

int main ()
{
	int N, answer = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &rope[i]);
	sort(rope+1, rope+N+1, [](int a, int b){
		return a > b;
	});
	
	for(int i = N; i >= 1; i--) {
		int w = rope[i]*i;
		answer = max(answer, w);
	}
	printf("%d", answer);
	return 0;
}