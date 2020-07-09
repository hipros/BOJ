#include<cstdio>
#include<algorithm>

int main ()
{
	int height[10], sum = 0, lier[2];
	int i, j;
	for(i = 0; i < 9; i++){
		scanf("%d", &height[i]);
		sum += height[i];
	}
	std::sort(height, height+9);
	for(i = 0;i < 9; i++){
		for(j = i; j < 9; j++){
			if(sum -height[i] -height[j] == 100){
				lier[0] = i;
				lier[1] = j;
				break;
			}
		}
		if(j != 9) break;
	}
	for(i = 0;i < 9; i++){
		if(i != lier[0] && i != lier[1])
			printf("%d\n", height[i]);
	}
	return 0;
}