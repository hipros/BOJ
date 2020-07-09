#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int T;
	cin >> T;
	while(T--){
		int N, M, t, answer = 0;
		vector<int> n;
		long long X = 0, Y = 0;
		cin >> N >> M;
		n.resize(N);
		for(int i = 0; i < M; i++){
			X *= 10;
			cin >> t;
			X += t;
		}
		for(int i = 0; i < M; i++){
			Y *= 10;
			cin >> t;
			Y += t;
		}
		for(int i = 0; i < N; i++) cin >> n[i];

		for(int i = 0; i < N; i++){
			long long Z = 0;
			for(int j = 0; j < M; j++){
				Z *= 10;
				t = (i + j) % N;
				Z += n[t];
			}
			if(X <= Z && Z <= Y) answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}