#include<bits/stdc++.h>
using namespace  std;
const int maxn = 4000005;
bool not_prime[maxn];
vector<int> prime;

int main()
{
    int N, h = 0, t = 0, cumulative_sum = 0, ans = 0; // h 뺄 인덱스, t 더할 인덱스
    int prime_size;
    cin >> N;
    for(int i = 2; i <= N; i++) {
        if(not_prime[i]) continue;
        prime.push_back(i);
        for(long long j = 1LL*i*i; j <= N; j += i) not_prime[j] = true;
    }
    prime_size = prime.size();

    while(!(t >= prime_size && h >= prime_size-1)) {
        if(cumulative_sum < N) { //누적합이 N보다 작을 때 +tail
            cumulative_sum += prime[t++];
        }
        else if(cumulative_sum >= N) { // 누적합이 N보다 크거나 같을 때 -head
            cumulative_sum -= prime[h++];
        }
        if(cumulative_sum == N) ans++;
    }

    cout<<ans;
    return 0;
}