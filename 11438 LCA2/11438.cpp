#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int n, k, num;
	int i[6], j1, j2;
	priority_queue<int, vector<int>, greater<int> > q;
	scanf("%d", &n);
	for(i[0] = 0;i[0] < 10; i[0]++){
		for(i[1] = 0;i[1] < 10; i[1]++){
			for(i[2] = 0;i[2] < 10; i[2]++){
				for(i[3] = 0;i[3] < 10; i[3]++){
					for(i[4] = 0;i[4] < 10; i[4]++){
						for(k = 0;k < 6; k++){
							num = 0;
							for(j1 = 0; j1 < 5 - k; j1++){
								num *= 10;
								num += i[j1];
							}
							num *= 1000;
							num += 666;
							for(j2 = 5 - k; j2 < 5; j2++){
								num *= 10;
								num += i[j2];
							}
							q.push(num);
						}
					}
				}
			}
		}
	}
	for(k = 0;k < n; k++) {
		num = q.top();
		while(num == q.top()) q.pop();
	}
	printf("%d", num);
	return 0;
}