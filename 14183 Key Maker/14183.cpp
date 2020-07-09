#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)12;

struct key{ int k[MAXN]; };
int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1){
		key cs;
		vector<key> tr;
		int M, N, ans = 0;

		cin>> M >>N;
		if(!M && !N) break;

		tr.resize(N);
		for(int i = 0; i < M; i++) cin>> cs.k[i];
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin>>tr[i].k[j];

		for(int i = 0; i < N; i++) {
			int p = 0;
			for(; p < M && tr[i].k[p] <= cs.k[p]; p++);
			if(p == M) ans++;
		}
		cout << ans <<'\n';
	}
	return 0;
}