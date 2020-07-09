#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005, INF = (int)(5e5) + 10, MAXR = 501;

short C[MAXR];
vector<short> conn[MAXR];
set<short> as, bs;
bool ahas[MAXR][MAXN];
int Answer = INF;

int main()
{
	int A, B, N, M;
	cin >> A >> B >> N;
	for(int t = 0; t < N; t++){
		bool ch[2] = {0,0};

		cin>> C[t]>> M; 
		conn[t].resize(M);

		for(int i=0; i < M; i++) {
			cin>> conn[t][i];
			ch[0] |= (conn[t][i] == A);
			ch[1] |= (conn[t][i] == B);

		}
		if(ch[0]) as.insert(t);
		if(ch[1]) bs.insert(t);
	}
	
	for(short t : as) {
		bool ac = false;
		for(int i : conn[t]) {
			if(ac) ahas[t][i] = true;
			if(i == A) ac = true;
			if(ac && i == B) {
				Answer = min(Answer, (int)C[t]);
				bs.erase(t);
			}
		}
	}

	for(short a : as) {
		for(short b : bs) {
			for(int i : conn[b]) {
				if(i == B) break;
				if(ahas[a][i]){
					Answer = min(Answer, C[a]+C[b]);
					break;
				} 
			}
		}	
	}
	
	if(Answer != INF) cout << Answer;
	else cout << -1;
	
	return 0;
}
