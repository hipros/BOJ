#include <bits/stdc++.h>
#define MAXN 200
#define MAXM 200
using namespace std;

int N, M, input;
vector<int> like[MAXN+1];
int reg[MAXM+1], visit[MAXN+1];

bool find(int x)
{
	for(int h : like[x]){
		if(reg[h]==0) {
			reg[h] = x;
			return true;
		}
		else if(reg[h]!=x && visit[reg[h]]!=1){
			visit[x] = 1;
			if(find(reg[h])){
				reg[h] = x;
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	int cnt = 0;
	scanf("%d %d", &N, &M);
	for(int i = 1;i <= N; i++){
		scanf("%d", &input);
		like[i].assign(input, 0);
		for(int j = 0;j < input; j++)
			scanf("%d", &like[i][j]);
	}
	for(int i = 1;i <=N; i++){
		if(find(i)) cnt++;
		for(int j = 1;j <= N; j++) visit[j] = 0;
	}
	printf("%d", cnt);
	return 0;
}