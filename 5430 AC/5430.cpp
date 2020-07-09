#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#define MAXLEN 100000
#define MAXN 100000

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int k = 0; k < T; k++)
	{
		int N, len, num[MAXN], nnum = 0;
		char string[MAXLEN],arr[2*MAXN+2];
		char *tok;
		scanf("%s", string);
		scanf("%s", &N);
		scanf("%s", arr);
		len = strlen(arr);
		strncpy(arr, arr, len-1);
		arr[0] = 0;
		tok = strtok(arr, ",");
		while (tok != NULL) {
			num[nnum++] = stoi(string(tok));
			tok = strtok(NULL, ",");
		}


	}

	int T = 10;

	while (T --> 0) {

	}

	return 0;
}
