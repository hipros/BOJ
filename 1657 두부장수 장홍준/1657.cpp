#include<bits/stdc++.h>
#define MAXN 15
int topu[MAXN][MAXN];
int state[MAXN][MAXN][MAXN*MAXN];

void dfs(int x, int y, int fill)
{
	
}
int main ()
{
	int toputable[5][5] = {
		{10,8,7,5,1},
		{8,6,4,3,1},
		{7,4,3,2,1},
		{5,3,2,2,1},
		{1,1,1,1,0}
	};
	int N, M;
	char c;
	scanf("%d %d", &N, &M);
	for(int i = 0;i < N: i++) {
		for(int j = 0; j < M; j++) {
			scanf("%c", &c);
			topu[i][j] = c - 'A';
		}
		getchar();
	}
	dfs(0,0,0);
	return 0;
}