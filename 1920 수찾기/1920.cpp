#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int)(1e5) + 5;
int A[MAXN], B;

int main ()
{
	int N, M;
	scanf("%d", &N);
	
	for(int i= 0 ; i < N; i++) scanf("%d", &A[i]);
	sort(A, A+N);

	scanf("%d", &M);
	for(int i= 0; i < M; i++) {
		int l, r;
		scanf("%d", &B);
		
		l = 0, r = N;
		while(l < r) {
			int mid = (l+r) /2;
			if(A[mid] < B) l = mid+1;
			else r = mid;
		}

		if(A[r] == B) printf("1\n");
		else printf("0\n");
	}

	return 0;
}