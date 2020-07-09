#include<bits/stdc++.h>
#define MAXl 1001
char str1[MAXl], str2[MAXl], answer[MAXl];
int dp[MAXl][MAXl], past[MAXl][MAXl];

int main ()
{
	int len1, len2, x, y, len = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	len1 = std::strlen(str1); len2 = std::strlen(str2);
	
	for(int i = 1;i <= len1; ++i) {
		for(int j = 1;j <= len2; ++j) {
			if(str1[i-1]== str2[j-1]) {
				dp[i][j] = dp[i-1][j-1] +1;
				past[i][j] = 1;
			}
			else{
				if(dp[i][j-1] > dp[i-1][j]){
					dp[i][j] = dp[i][j-1];
					past[i][j] = 2;
				}
				else {
					dp[i][j] = dp[i-1][j];
					past[i][j] = 3;
				}
			}
		}
	}
	printf("%d\n", dp[len1][len2]);
	x = len1; y = len2;
	len = dp[len1][len2];
	while (x != 0 && y != 0) {
		if (past[x][y] == 1) {
			--x; --y;
			answer[--len] = str1[x];
		}
		else if (past[x][y] == 2) --y;
		else --x;
	}
	answer[dp[len1][len2]] = '\0';
	printf("%s", answer);
	return 0;
}