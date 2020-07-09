#include<cstdio>
#define MAXSIZE 6145
bool table[MAXSIZE][MAXSIZE];

void fractal(int t, int b, int verx)
{
	if (b - t == 2) {
		table[t][verx] = true;
		table[t+1][verx-1] = true; table[t+1][verx+1] = true;
		for (int i = 0; i <= 2; i++) { table[t + 2][verx - i] = true, table[t + 2][verx + i] = true; }
	}
	else {
		fractal(t, (b + t) / 2, verx);
		fractal((t+b) / 2 + 1, b, verx - ((b - t) / 2) - 1);
		fractal((t+b) / 2 + 1, b, verx + ((b - t) / 2) + 1);
	}
}

int main()
{
	int N, k = 0, b = 2;
	scanf("%d", &N);
	N /= 3;
	while (N > 1) { N /= 2, k++; }
	for (int i = 0; i < k; i++) b = b * 2 + 1;
	fractal(0, b, b);

	for (int i = 0; i <= b; i++) {
		for (int j = 0; j <= 2 * b; j++) {
			if (table[i][j] == 1) putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}

	//system("pause");
	return 0;
}