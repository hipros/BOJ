#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for(int T = 1;; T++){
		int A[MAXN][MAXN], B[MAXN][MAXN];
		int answer[MAXN][MAXN] = {0,};
		int M, N, P, Q;
		cin >> M >> N >> P >> Q;
		if(!M) break;
		cout << "Case #"<<T<<":\n";
		for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) cin >> A[i][j];
		for(int i = 0; i < P; i++) for(int j = 0; j < Q; j++) cin >> B[i][j];

		if(N == P) {
			for(int i = 0; i < M; i++) for(int k = 0; k < Q; k++) for(int j = 0; j < N; j++)  answer[i][k]+= (A[i][j] * B[j][k]);
			for(int i = 0; i < M; i++){
				cout << "| ";
				for(int j = 0; j < Q; j++) cout << answer[i][j] << " ";
				cout <<"|\n";
			}
		}
		else cout << "undefined\n";
	}
	return 0;
}