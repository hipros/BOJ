#include<bits/stdc++.h>
using namespace std;
const int maxn = 128;
int m[maxn + 1][maxn + 1], b, w;

void d(int sx, int sy, int ex, int ey)
{
    int cnt = m[ex][ey] + m[sx-1][sy-1] - m[sx-1][ey] - m[ex][sy-1];
    if (cnt == 0) w++;
    else if (cnt == (ex - sx+1) * (ey - sy+1)) b++;
    else {
        int mx = (sx + ex) / 2, my = (sy + ey) / 2;
        d(sx, sy, mx, my);
        d(sx, my+1, mx, ey);
        d(mx+1, sy, ex, my);
        d(mx + 1, my + 1, ex, ey);
    }
}

int main()
{
    int N, t;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> t;
            m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + t;
        }
    }
    d(1, 1, N, N);
    cout << w << '\n' << b;
    return 0;
}