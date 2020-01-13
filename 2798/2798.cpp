#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int c[MAXN], answer = 0;

int main()
{
    int N, M;
    cin>>N >>M;
    for(int i = 0; i < N; i++) cin>>c[i];

    int sum=0;
    for(int i = 0; i < N; i++){
        sum = c[i];
        for(int j = i+1; j < N; j++){
            sum += c[j];
            for(int k = j+1; k < N; k++){
                sum += c[k];
                if(sum <= M && answer < sum) answer = sum;
                sum -= c[k];
            }
            sum -= c[j];
        }
    }
    cout<<answer;
    return 0;
}