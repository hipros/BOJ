#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5, inf = 2e9;

int N, H[maxn+1];

ll DC(int s, int e)
{
    if(e-s == 1) return 1LL * H[s];
    int m = (s+e)/2 + ((s+e)%2);
    ll left = DC(s, m), right = DC(m, e);
    int l = m-1, r = m;
    int minh = min(H[l], H[r]);
    ll w = 2LL * minh;
    l--; r++;

    while(l >= s || r < e){
        int len = r-l;
        if(r >= e || (l >= s && H[l] > H[r])) minh = min(minh, H[l--]);
        else minh = min(minh, H[r++]);

        w = max(w, 1LL * minh * len);
    }
    return max(w, max(left, right));
}

int main()
{
    while(1){
        scanf("%d", &N);
        if(N == 0) break;
        for(int i = 0; i < N; i++) scanf("%d", &H[i]);

        printf("%lld\n", DC(0, N));
    }
    return 0;
}