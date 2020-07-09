#include<stdio.h>
#include<string.h>
#pragma warning(disable: 4996)

int main()
{
	char fname[51] = {0,};
	char pat[51] = { 0, };
	int N, i, j, len;
	
	scanf("%d", &N);

	for (i = 0 ; i< N; i++) {
		scanf("%s", fname);
		if (i == 0) {
			len = strlen(fname);
			strcpy(pat, fname);
		}
		else {
			for (j = 0; j < len; j++) {
				if (pat[j] != fname[j]) {
					pat[j] = '?';
				}
			}
		}
	}
	printf("%s", pat);
	system("PAUSE");
	return 0;
}