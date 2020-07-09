#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int N, answer = 0;
	int fl[3], ml[3];
	cin >> N;
	for(int i= 0; i< 3; i++) cin >> fl[i];
	for(int i= 0; i< 3; i++) cin >> ml[i];

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++){
				int t1 = abs(i - fl[0]), t2 = abs(j - fl[1]), t3 = abs(k - fl[2]);
				int l1 = abs(i - ml[0]), l2 = abs(j - ml[1]), l3 = abs(k - ml[2]);
				t1 %= (N-2); t2 %= (N-2); t3 %= (N-2);
				l1 %= (N-2); l2 %= (N-2); l3 %= (N-2);

				if((t1 <= 2 && t2 <= 2 && t3 <= 2) ||
					(l1 <= 2 && l2 <= 2 && l3 <= 2))
					answer++;
			}
		}
	}
	cout << answer;
	return 0;
}