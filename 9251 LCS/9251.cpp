#include<bits/stdc++.h>
#define MAXL 4000
using namespace std;

int dp[MAXL+1][MAXL+1];

int main ()
{
	char str1[MAXL+1], str2[MAXL+1];
	int answer = 0;
	scanf("%s", str1);
	scanf("%s", str2);

	for(int i = 1;i <= strlen(str1); ++i){
		for(int j = 1;j <= strlen(str2); ++j){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
		}
	}

	printf("%d", dp[strlen(str1)][strlen(str2)]);
	return 0;
}
