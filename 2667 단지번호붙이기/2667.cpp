#include<bits/stdc++.h>
#define MAXN 26
using namespace std;

char Map[MAXN][MAXN];
int N;

int dfs(int x, int y) 
{
	int ret[4] = {0,};
	Map[x][y] = '0';
	if(x > 0 && Map[x-1][y] == '1') ret[0] = dfs(x-1, y);
	if(x+1 < N && Map[x+1][y] == '1') ret[1] = dfs(x+1, y);
	if(y > 0 && Map[x][y-1] == '1') ret[2] = dfs(x, y-1);
	if(y+1 < N && Map[x][y+1] == '1') ret[3] = dfs(x, y+1);
	return ret[0]+ret[1]+ret[2]+ret[3]+1;
}

int main ()
{
	vector<int> answer;
	scanf("%d", &N);
	for(int i = 0;i < N; i++) scanf("%s", Map[i]);

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(Map[i][j] == '1') answer.push_back(dfs(i, j));
		}
	}	
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for(unsigned int i = 0; i < answer.size(); i++) printf("%d\n", answer[i]);
	return 0;
}