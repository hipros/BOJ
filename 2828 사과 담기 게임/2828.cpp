#include<bits/stdc++.h>

int main ()
{
	int N, M, J, x, l = 1, answer = 0;
	scanf("%d %d %d", &N, &M, &J);
	for(int i = 0; i < J; i++){
		scanf("%d", &x);
		if(x < l) {
			answer += (l - x);
			l = x; 
		}
		else if(x >= l+M){
			answer += (x - (l+M-1));
			l = x - M+1;
		}
	}
	printf("%d", answer);
	return 0;
}