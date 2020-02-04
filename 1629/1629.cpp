#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A, B, C;

ll calc(int b)
{
    if (b == 1) return A;

    int m = b / 2;
    ll c = calc(b / 2);

    c = (c*c) % C;
    if (b % 2 == 1) c = (c*A) % C;

    return c;
}

int main()
{
    int i;
    cin >> A >> B >> C;
    A = A % C;

    cout << calc(B) <<'\n';
    return 0;
}