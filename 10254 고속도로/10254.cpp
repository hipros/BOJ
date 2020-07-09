#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAXN 200000
#define MAXP 10000000
struct point
{
	long long x, y;
};

int ccw(point a, point b, point c)
{
	long long t = 
}

int main ()
{
	int T, n, minindex = 0;
	point p[MAXN+1], min;
	scanf("%d", &T);

	for(;T;--T){
		scanf("%d", &n);
		memset(p, 0, sizeof(p)*n); minindex = 0; min.x = MAXP; min.y = MAXP;

		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &p[i].x, &p[i].y);
			if(min.y > p[i].y || min.y == p[i].y && min.x > p[i].x){
				min = p[i];
				minindex = i;
			}
		}
		swap();
		sort(p+1, p+n, [](point a, point b) {
			return ccw(p[0], a, b) > 0;
		}
			);
		}
	}
	return 0;
}