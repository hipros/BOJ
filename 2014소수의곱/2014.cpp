#include<stdio.h>
#include<queue>
#define MAXN 100
using namespace std;

priority_queue<int> q;
int K, N;
int num[MAXN];

int main ()
{
	scanf("%d %d", &K, &N);
	for(int i = 0;i < K; i++)
		scanf("%d", &num[i]);
	
	for(int i = 0;i < K; i++)
		for(int j = i; j < K; j++)
					q.push(num[i]*num[j]);

	for(int i = 0;i < N-1; i++)
		q.pop();

	printf("%d", q.top());

	return 0;
}