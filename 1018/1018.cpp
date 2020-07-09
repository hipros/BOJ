#include<bits/stdc++.h>
const int MAXN = 51, INF = 2e9;
using namespace std;

bool m[MAXN][MAXN] = {0,};

int main() {
    char input;
    int N, M, answer = INF;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (input == 'W') m[i][j] = 1;
        }
        getchar();
    }

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            bool f = m[i][j];
            int cnt = 0;

            for (int y = i; y < i+8; y++) for (int x = j; x < j+8; x++) {
                    int dis = (y-i)+(x-j);
                    if(((dis % 2 == 0)?f:f^1) != m[y][x]) cnt++;
                }
            answer = min(answer, min(cnt, 64-cnt));
        }
    }
    cout<< answer;
    return 0;
}