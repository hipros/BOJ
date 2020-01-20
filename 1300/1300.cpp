#include<bits/stdc++.h>
using namespace std;

int main() {
    int s, e, ans;
    int N, K, seq;
    scanf("%d %d", &N, &K);
    s = 1; e = K;

    while (s<=e) {
        int m = (s + e) / 2;
        seq = 0;
        for (int i = 1; i <= N; i++) seq += min(N, m/i);

        if (seq < K) s = m+1;
        else {
            ans = m;
            e = m-1;
        }
    }

    printf("%d", ans);
    return 0;
}