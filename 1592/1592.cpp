#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b) //a > b
{
    while(b){
        int t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main ()
{
    int N, M, L, gcd = 0;
    cin >> N >> M >> L;
    gcd = GCD(N, L);
    cout << (M-1) * (N/gcd);
    return 0;
}