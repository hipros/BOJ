#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

int main ()
{
	int N, answer = 0;
	int A[MAXN], B[MAXN];
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	sort(A+1, A+N+1, [](int a, int b){
		return a < b;
	});
	sort(B+1, B+N+1, [](int a, int b){
		return a > b;
	});
	for(int i = 1; i <= N; i++) answer += A[i]*B[i];

	printf("%d", answer);
	return 0;
}