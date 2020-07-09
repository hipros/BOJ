#include<bits/stdc++.h>
using namespace std;
const int B = 'B' - 'A',E = 'E' - 'A',S = 'S' - 'A',I = 'I' - 'A',G = 'G' - 'A',O = 'O' - 'A',M = 'M' - 'A';

long long cnt[28][7];

int main ()
{
	long long answer = 0;
	int N;
	cin>>N;
	for(int i = 0; i < N; i++){
		char input;
		int c;
		cin>> input >>c;
		if(c > 0) cnt[input-'A'][c%7]++;
		else cnt[input-'A'][(c%7+7)%7]++;
	}

	for(int b = 0; b < 7; b++){
		for(int e = 0; e < 7; e++){
			for(int s = 0; s < 7; s++){
				for(int i = 0; i < 7; i++){
					for(int g = 0; g < 7; g++){
						for(int o = 0; o < 7; o++){
							for(int m = 0; m < 7; m++){	
								if((b+e+s+s+i+e) % 7 != 0 && (g+o+e+s) % 7 != 0 && (m+o+o) % 7 != 0) continue;
								answer += cnt[B][b] * cnt[E][e] * cnt[S][s] * cnt[I][i] * cnt[G][g] * cnt[O][o] * cnt[M][m];
							}	
						}	
					}	
				}	
			}	
		}	
	}
	cout << answer;
	return 0;
}