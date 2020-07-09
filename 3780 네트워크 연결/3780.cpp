#include<bits/stdc++.h>
#define MAXN 20005
int gp[MAXN], conlen[MAXN];

void lzUpdate(int node)
{
	int &len = conlen[node];
	int par = gp[node];
	while(par != gp[par])
	{
		len += conlen[par];
		par = gp[par];
	}
	gp[node] = par;
}
void unionCom(int a, int b)
{
	if (gp[a] != gp[gp[a]] && gp[gp[a]] && gp[a]) lzUpdate(a);
	if (gp[b] != gp[gp[b]] && gp[gp[b]] && gp[b]) lzUpdate(b);
	conlen[a] = conlen[b] + (abs(a - b) % 1000);
	if (gp[b]) gp[a] = gp[b];
	else {
		gp[a] = b;
		gp[b] = b;
	}
}

int main()
{
	char input;
	int N, T, a, b;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		memset(gp, 0, sizeof(int) * (N+1));	
		memset(conlen, 0, sizeof(int) * (N + 1));

		while (true) {
			scanf(" %c", &input);
			if (input == 'O') break;
			if (input == 'E') {
				scanf("%d", &a);
				if (gp[a] != gp[gp[a]]) lzUpdate(a);
				printf("%d\n", conlen[a]);
			}
			else {
				scanf("%d %d", &a, &b);
				unionCom(a, b);
			}
		}
	}
	return 0;
}