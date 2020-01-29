#include<bits/stdc++.h>
using namespace std;
struct d{int s, e;};
priority_queue<int, vector<int>, greater<>> pq;
vector<d> t;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    t.resize(N);
    for(int i = 0; i < N; i++) cin>>t[i].s>>t[i].e;
    sort(t.begin(), t.end(), [](const d& a, const d& b){
        return a.s < b.s || a.s == b.s && a.e > b.e;
    });

    for(d now:t){
        if(pq.empty() || pq.top() > now.s) pq.push(now.e);
        else {
            pq.pop();
            pq.push(now.e);
        }
    }
    cout<<pq.size();
    return 0;
}