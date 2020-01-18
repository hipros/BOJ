#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5;

int N, H[maxn+1];
stack<pair<int, int> > s;

int main ()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &H[i]);

    for(int i = 0; i < N; i++) {
        while(!s.empty() && s.top().second <= H[i]) s.pop();

        if(s.empty()) printf("0 ");
        else printf("%d ", s.top().first);

        s.push({(}i+1, H[i]});
    }
    return 0;
}