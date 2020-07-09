#include<cstdio>
#include<algorithm>
#include<stack>
#define MAXN 50
using namespace std;
typedef struct Point
{
	int x;
	int y;
}point;

point po;
void swap(point* a, point *b)
{
	point t = *a;
	*a = *b;
	*b = t;
}
int ccw(point a, point b, point c)
{
	int t= a.x*b.y+b.x*c.y+c.x*a.y;
	t-= a.y*b.x + b.y*c.x+c.y*a.x;
	if(t == 0) return 0;
	return (t < 0)?-1:1;
}
int dist(point a, point b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
point secondTop(stack<point> S)
{
	point t = S.top(); S.pop();
	point sTop = S.top();
	S.push(t);
	return sTop;
}
bool compare(point& a, point& b)
{
	int t = ccw(po, a, b);
	if(t == 0) return (dist(po, a) < dist(po, b)) ? true:false;
	return (t > 0) ? true:false;
}
int main ()
{
	int T, n;
	point p[MAXN+1];
	scanf("%d", &T);
	for(;T; --T){
		int mini = 0;
		stack<point> S;
		po.y = -21; po.x = 21;
		scanf("%d", &n);
		for(int i = 0;i < n; i++){
			scanf("%d %d", &p[i].x, &p[i].y);
			if(po.y < p[i].y || (po.y == p[i].y && po.x > p[i].x)){
				po.x = p[i].x; po.y = p[i].y;
				mini = i;
			}
		}

		swap(p[0], p[mini]);
		sort(p+1, p+n, compare);

		S.push(p[0]); S.push(p[1]);

		for(int i = 2;i < n; i++){
			while(S.size() >= 2 && ccw(secondTop(S), S.top(), p[i]) <= 0) S.pop();
			S.push(p[i]);
		}
		printf("%d\n", S.size());
		printf("%d %d\n", po.x, po.y);
		while(S.size() > 1) {
			printf("%d %d\n", S.top().x, S.top().y);
			S.pop();
		}
	}
	return 0;
}