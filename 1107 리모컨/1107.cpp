#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int N,brokenn, input, maxnumber = 0, minnumber = 0;
	int number[10], t, n[6], len= 0;
	scanf("%d", &N);
	scanf("%d", &brokenn);
	for(int i = 0;i < brokenn; i++){
		scanf("%d", &input);
		number[input] = 1;
	}
	for(int i = 0;i < 10; i++){
		if(!number[i]) {
			maxnumber = max(maxnumber, i);
			minnumber = min(minnumber, i);
		}
	}
	t = N;
	while(t!=0){
		int a = t%10;
		t /= 10;
		n[len]= a;
		len++;
	}
	t = N;
	while(t != 0){
		
	}
	return 0;
}