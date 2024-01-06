#include <iostream>
#include <cstdio>
#include <vector>
#define N 505
using namespace std;

int n, m, tc = 1, cnt, ch, v[N];
vector<int> a[N];
void f(int p, int q) {
    int i;
    if (v[p] == tc) {ch = 1; return;}
    v[p] = tc;
    for (i = 0; i < a[p].size(); i++) {
        if (a[p][i] != q) f(a[p][i], p);
    }
}

int main()
{
    int i, t1, t2;
    freopen ("input.txt", "r", stdin);
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        for (i = 1; i <= n; i++) {
            a[i].clear();
        }
        for (i = 0; i < m; i++) {
            scanf("%d %d", &t1, &t2);
            a[t1].push_back(t2);
            a[t2].push_back(t1);
        }
        cnt = 0;
        for (i = 1; i <= n; i++) {
            if (v[i] == tc) continue;
            ch = 0;
            f(i, -1);
            if (!ch) cnt++;
        }
        printf("Case %d: ", tc);
        if (cnt == 0) printf("No trees.\n");
        else if (cnt == 1) printf("There is one tree.\n");
        else printf("A forest of %d trees.\n", cnt);
        tc++;
    }
    return 0;
}
