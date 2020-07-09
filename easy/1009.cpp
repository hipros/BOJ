#include<cstdio>
#include<cstring>

int main ()
{
	int n, i,ch[10];
	int a, b, nextseq, seq;
	scanf("%d", &n);
	for(;n;--n){
		memset(ch, -1, 10*sizeof(int));
		seq = 0;
		scanf("%d %d", &a, &b);
		a %= 10;
		nextseq = a;
		while(ch[nextseq]==-1){
			ch[nextseq] = ++seq;
			nextseq = (nextseq * a)% 10;
		}
		for(i = 0;i < 10; i++){
			int c = (b%seq) ? b%seq:seq;
			if(ch[i] == c) {
				if(i == 0) printf("10\n");
				else printf("%d\n", i);
				
				break;
			}
		}
	}
	return 0;
}