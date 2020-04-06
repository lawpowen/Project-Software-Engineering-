#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <limits.h>
#include <math.h>
using namespace std;
struct point
{
    long long int x;
    long long int y;
};
point p[100100], btm, st[100100];
stack<point> s;
bool cmp(point a, point b)
{
    return (a.y < b.y);
}
bool cmp2(point a, point b)
{
    if (fabs((a.x - btm.x) * (b.y - btm.y) - (b.x - btm.x) * (a.y - btm.y)) <= 1e-8)
        return fabs(btm.x - a.x) < fabs(btm.x - b.x);
    return (((a.x - btm.x) * (b.y - btm.y) - (b.x - btm.x) * (a.y - btm.y)) > 0);
}
int main()
{
    int N, top = -1;
    double dist = 0, area = 0, sum = 0;
    scanf("%d", &N);
    btm.y = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &p[i].x, &p[i].y);
        if (btm.y > p[i].y)
        {
            btm.x = p[i].x;
            btm.y = p[i].y;
        }
    }
    sort(p, p + N, cmp2);
    st[++top] = p[0];
    st[++top] = p[1];
    for (int i = 2; i < N; i++)
    {
        while (((st[top].x - p[i].x) * (st[top - 1].y - p[i].y) - (st[top - 1].x - p[i].x) * (st[top].y - p[i].y)) > 0)
        {
            top--;
        }
        st[++top] = p[i];
    }
    for (int i = 0; i < top; i++)
    {
        dist += sqrt(((st[i].x - st[i + 1].x) * (st[i].x - st[i + 1].x) + (st[i].y - st[i + 1].y) * (st[i].y - st[i + 1].y)));
    }
    dist += sqrt(((st[top].x - st[0].x) * (st[top].x - st[0].x) + (st[top].y - st[0].y) * (st[top].y - st[0].y)));
    for (int i = 0; i < top; i++)
    {
        area += (st[i].x * st[i + 1].y) - (st[i].y * st[i + 1].x);
    }
    area += abs(((st[top].x * st[0].y) - (st[top].y * st[0].x)));
    area /= 2;
    printf("%.2lf %.2lf", dist, area);
    return 0;
}