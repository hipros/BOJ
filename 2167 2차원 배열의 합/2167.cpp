#include<bits/stdc++.h>
using namespace std;
int table[301][301];

int main ()
{
	int N, M, K;
	cin>> N >>M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin>>table[i][j];
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) table[i][j] += table[i][j-1];
	cin >> K;
	while(K--){
		int i, j, x, y, sum = 0;
		cin>>i>>j>>x>>y;
		for(int a = i; a<= x; a++) sum += (table[a][y] - table[a][j-1]);
		cout<<sum<<'\n';
	}
	return 0;
}