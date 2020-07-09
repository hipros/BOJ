#include<bits/stdc++.h>
#define MAXN (int)1e5 + 5
using namespace std;

int main()
{
	int num[MAXN], len = 0, sum = 0;
	while(scanf("%1d", &num[len])==1) sum += num[len++];
	sort(num, num+len, [](int a, int b){
		return a > b;
	});
	if((sum % 3) || num[len-1] != 0) printf("-1");
	else {
		for(int i = 0; i < len; i++) 
			printf("%d", num[i]);
	}
	return 0;
}