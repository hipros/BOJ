#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int> > ans;

void move(int f, int t, int temp, int n)
{
    if (n == 1) ans.push_back({ f, t });
    else {
        move(f, temp, t, n-1);
        move(f, t, temp, 1);
        move(temp, t, f, n - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N;
    move(1, 3, 2, N);
    cout << ans.size()<<'\n';
    for (pair<int, int> a : ans) cout << a.first << " " << a.second << '\n';
    return 0;
}