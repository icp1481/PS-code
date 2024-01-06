#include <iostream>
#include <cstdio>
#include <queue>
#define N 200005
using namespace std;

int n, m, cu, d[N];
bool v[N];
queue<int> q1, q2;
int f(int p, int w) {
    if (p < 0 || p > cu) return 0;
    if (v[p]) {d[p] = min(d[p], w); return 1;}
    d[p] = w;
    v[p] = 1;
    q1.push(p);
    return 1;
}

int main()
{
    int i, t, t1, t2;
    cin >> n >> m;
    cu = max(n, m * 2);
    f(n, 0);
    while (!q1.empty()) {
        t1 = q1.front(); q1.pop();
        if (t1 == m) {
            cout << d[t1];
            return 0;
        }
        f(t1 + 1, d[t1] + 1);
        if (t1 == 0) continue;
        f(t1 - 1, d[t1] + 1);
        i = t1;
        while (1) {
            if (!f(i, d[t1])) break;
            i *= 2;
        }
    }
    return 0;
}
