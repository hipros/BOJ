#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
bool ch[maxn];

int main ()
{
	int N, M = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) M ^= i;
	for(int i = 0; i < N-1; i++) {
		int m, t;
		cin >> m >> t;

		if(ch[m]) {
			M = -1;
			break;
		}
		ch[m] ^= 1;
		M ^= m;
	}
	cout << M;
	return 0;
}