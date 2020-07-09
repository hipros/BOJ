#include<bits/stdc++.h>
#define MAXN 101
using namespace std;

pair<short, short> edge[MAXN*MAXN/2];
bool infection[MAXN];
int main ()
{
	int N, M, cnt = 0;
	bool ch = true;
	scanf("%d\n%d", &N, &M);
	for(int i = 0;i < M; i++) {
		scanf("%hd %hd", &edge[i].first, &edge[i].second);
	}
	infection[1] = true;
	for(int i = 1; i <= N-1 && ch; i++) {
		ch = false;
		for(pair<short, short> inf : edge){
			if(infection[inf.first] ^ infection[inf.second]){
				infection[inf.first] |= 1;
				infection[inf.second] |= 1;
				ch = true;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}