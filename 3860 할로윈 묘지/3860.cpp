#include<bits/stdc++.h>
#define MAXN 30
#define INF 2e9
using namespace std;
int H, W;
int map[MAXN][MAXN];

struct xy {
	int x, y;
};
int bfs(xy start)
{
	queue<xy> q;
	q.push_back(start);
	whlie(!q.empty()){
		xy cur;
		cur = q.front(); q.pop();
		if(cur.x > 0 && sur.y > 0)
	}
}	
int main ()
{
	int T, tx, ty, G, gsx, gsy, gex[MAXN*MAXN], gey[MAXN*MAXN], gt[MAXN*MAXN];
	int i;
	while(1){
		xy start = {0, 0};
		scanf("%d %d", &W, &H);	
		if(W==0&&H==0) break;
		scanf("%d", &T);
		for(i = 0;i < T; i++){
			scanf("%d %d", &tx, &ty);
			map[tx][ty] = INF;
		}
		scanf("%d", &G);
		for(i = 1;i <= G; i++){
			scanf("%d %d %d %d", &gsx, &gsy, &gex[i], &gey[i], &gt[i]);
			map[gsx][gsy] = -1 * i;
		}
		bfs(start);
	}
	return 0;
}



for(int i=1; i<=n; i++){
        dp[i] = query2()//query2를 이용해서 dp[i]를 구함.
        ins.a = -2*a*sum[i]+b;
        ins.b = dp[i]-b*sum[i]+a*sum[i]*sum[i];
        cht.insert(ins,i);// convex에 추가.
    }


