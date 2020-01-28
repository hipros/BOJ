#include<bits/stdc++.h>
using namespace std;
const int maxn = 250, S = 'S'-'0', K = 'K'-'0';

struct node{  int x, y; };
struct edge{ int s, e, v; };
bool operator<(const edge& a, const edge& b){ return a.v > b.v; }
int N, M,m[maxn+5][maxn+5];
int d[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
int conn[maxn+5][maxn+5], g[maxn+5];
queue<node> q;
vector<node> k;
priority_queue<edge> pq;

bool isin(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

void bfs(int sind, int sx, int sy)
{
    short dis[maxn][maxn] = {0,};
    q.push({sx, sy});

    while(!q.empty()){
        node now = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int x = now.x + d[i][0], y = now.y + d[i][1];
            if(isin(x, y) && dis[x][y] == 0 && m[x][y] != 1 && !(x == sx && y == sy)) {
                dis[x][y] = dis[now.x][now.y] + 1;
                q.push({x, y});
            }
        }
    }

    for(int i = 0; i < k.size(); i++) conn[sind][i] = dis[k[i].x][k[i].y];
}
int f(int x)
{
    if(g[x] == x) return x;
    return g[x] = f(g[x]);
}
void u(int p, int q)
{
    int pp = f(p), qq = f(q);
    g[pp] = g[qq];
}
int main ()
{
    int ans = 0;
    char input;
    scanf("%d %d ", &N, &M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%c", &input);
            m[i][j] = input-'0';
            if(m[i][j] == S) k.push_back({i, j});
            else if(m[i][j] == K) k.push_back({i, j});
        }
        getchar();
    }

    for(int i = 0; i < M+1; i++) bfs(i, k[i].x, k[i].y);
    for(int i = 0; i < M+1; i++) for(int j = 0; j < M+1; j++) if(conn[i][j] != 0) pq.push({i, j, conn[i][j]});
    for(int i = 0; i < M+1; i++) g[i] = i;

    bool impossible = false;
    edge now;

    for(int i = 0; i < M && !impossible; i++) {
        do {
            now = pq.top(); pq.pop();
        }while(f(now.s) == f(now.e) && !pq.empty());
        if(f(now.s) == f(now.e)) impossible = true;

        u(now.s, now.e);
        ans += now.v;
    }

    if(impossible) printf("-1");
    else printf("%d", ans);
    return 0;
}