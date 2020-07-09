#include<bits/stdc++.h>
using namespace std;
const int N = 10;

int main ()
{
	int optb[N][N], ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0;j < N; j++) cin>> optb[i][j];
	for(int a = 0; a< N; a++){
		int v = optb[0][a];
		for(int b = 0; b< N; b++){
			v = optb[v][b];
			for(int c = 0; c< N; c++){
				v = optb[v][c];
				for(int d = 0; d< N; d++){
					v = optb[c][d];
					for(int e = 0; e< N; e++){
						if(v != e) ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}