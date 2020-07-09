#include<cstdio>
#define MAXN 64

int matrix[MAXN][MAXN];

bool check(int x, int y, int n)
{
	int t = 0;
	for(int i = x;i <x+n; i++){
		for(int j = y; j < y+n; j++){
			t += matrix[i][j];
		}
	}
	if(t == 0 || t == n*n) return true;
	else return false;
}
void dc( int x, int y, int n)
{
	if(check(x, y, n) == true){
		printf("%d", (matrix[x][y]==1)? 1:0 );
	}
	else{
		printf("(");
		dc(x, y, n/2);
		dc(x, y+n/2, n/2);
		dc(x+n/2, y, n/2);
		dc(x+n/2, y+n/2, n/2);
		printf(")");
	}
}
int main ()
{
	int n, i, j;
	scanf("%d", &n);
	for(int i = 0;i < n; i++){
		getchar();
		for(int j = 0;j < n; j++){
			matrix[i][j] = getchar()-'0';
		}
	}

	dc(0, 0, n);
	return 0;
}