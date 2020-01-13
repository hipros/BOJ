#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;

pair<int, int> d[MAXN];
int r[MAXN];

int main ()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) cin>>d[i].first>>d[i].second;

    for(int i = 0; i < N; i++) {
        r[i]=1;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(d[i].first < d[j].first && d[i].second < d[j].second) r[i]++;
        }
    }

    for(int i = 0;i < N; i++) cout<<r[i]<<'\n';
    return 0;
}