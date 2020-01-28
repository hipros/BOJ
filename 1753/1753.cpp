#include<bits/stdc++.h>
using namespace std;
const int maxn = 20000, inf = 4e6;
struct edge { int s, e, v; };

bool operator<(const edge& a, const edge& b) {
    return a.v > b.v;
}

int V, E, S;
priority_queue<edge> pq;
vector<edge> c[maxn+5];
bool vis[maxn + 5];
int dis[maxn + 5];

int main()
{
    int s, e, v;
    cin >> V >> E;
    cin >> S;
    for (int i = 0; i < E; i++) {
        cin >> s >> e >> v;
        c[s].push_back({s, e, v});
    }
    for (int i = 1; i <= V; i++) dis[i] = inf;
    for (edge e : c[S]) {
        pq.push({ S, e.e, e.v });
        dis[e.e] = e.v;
    }
    vis[S] = 1; dis[S] = 0;

    while (!pq.empty()) {
        edge now = pq.top(); pq.pop();
        if (vis[now.e] && dis[now.e] < now.v) continue;
        vis[now.e] = 1;

        for (edge next : c[now.e]) {
            if (!vis[next.e] && dis[next.e] > dis[now.e] + next.v) {
                dis[next.e] = dis[now.e] + next.v;
                pq.push({ S, next.e, dis[next.e] });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dis[i] == inf) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
    return 0;
}