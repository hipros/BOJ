#include<bits/stdc++.h>
#define MAXS 2188
using namespace std;

int pmap[MAXS][MAXS];
int pcnt[3];

int check(int N, int sx, int sy)
{
	int ex = sx+N, ey = sy+N;
	int i, j, cnt = 0;
	int sqsm=-2;
	for(i = sx;i < ex; i++){
		for(j = sy;j < ey; j++){
			if(sqsm== -2 || sqsm==pmap[i][j]) sqsm = pmap[i][j];
			else {
				return -1;
			}
		}
	}
	if(sqsm == -1) return 0;
	else if(sqsm==0) return 1;
	else if(sqsm== 1) return 2;
}
void dfs(int N, int sx, int sy)
{
	int ex = sx+N, ey = sy+N;
	int c = check(N, sx, sy);
	if(c>-1 && c<3){
		pcnt[c]++;
		return ;
	}
	for(int i = 0;i < 3; i++)
		for(int j = 0;j < 3; j++)
			dfs(N/3, sx+(N/3)*i, sy+(N/3)*j);
	return ;
}

int main ()
{
	int N, i, j;
	scanf("%d", &N);
	for(i = 0;i < N; i++)
		for(j = 0;j < N; j++)
			scanf("%d", &pmap[i][j]);

	dfs(N, 0, 0);
	for(i = 0;i < 3; i++)
		printf("%d\n", pcnt[i]);
	return 0;
}