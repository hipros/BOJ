#include<bits/stdc++.h>
using namespace std;

vector<int> br;
int T;

int main ()
{
	scanf("%d", &T);
	for(;T;--T){
		br.clear();
		int  N, k;
		char BW[2] = {0,};
		scanf("%d", &N);
		for(int i = 0;i < N; i++){
			scanf("%d %c", k, BW[1]);
			if(BW[1]==BW[0])
				br[br.size()-1] += k;
			else {
				br.push_back(k);
				BW[0] = BW[1];
			}
		}
		if(br.size()==1)
			printf("%d\n", br[0]);
		else if(br.size() == 2)
			printf("1\n");
		else if(br.size() %2 == 0){

		}
		else{

		}
	}
	return 0;	
}
