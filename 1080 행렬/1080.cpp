#include<bits/stdc++.h>
#define MAXN 55
bool map[MAXN][MAXN], input;

void convert(int x, int y) 
{
	for(int i = x; i < x+3; i++) for(int j = y; j < y+3; j++) map[i][j] ^= 1;
}
int main ()
{
	int N, M, cnt = 0, i, j;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) for(j = 0; j < M; j++) scanf("%1d", &map[i][j]);
	for(i = 0; i < N; i++) for(j = 0; j < M; j++) scanf("%1d", &input),	map[i][j] ^= input;
	for(i = 0; i < N-2; i++) {
		for(j = 0; j < M-2; j++) {
			if(map[i][j]) {
				convert(i, j);
				cnt++;
			}
		}
	}
	for(i = 0, j = M; i < N && j == M; i++) for(j = 0; j < M && !map[i][j]; j++); 
	if(i == N && j == M) printf("%d", cnt);
	else printf("-1");
	return 0;
}