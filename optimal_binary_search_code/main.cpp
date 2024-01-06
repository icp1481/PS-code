#include <iostream>
#include <cstdio>
#include <queue>
#define N 1005
using namespace std;

int n, e[N][N], roo[N][N], s[N], a[N];
queue<int> ql, qr;
int main()
{
    int l, i, j, r, t, pl, tl, tr;
    freopen ("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n + 1; i++) {
        e[i][i - 1] = 0;
    }
    for (i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (l = 1; l <= n; l++) {
        for (i = 1; i + l - 1 <= n; i++) {
            j = i + l - 1;
            pl = s[j] - s[i - 1];
            e[i][j] = 1e9;
            for (r = i; r <= j; r++) {
                t = e[i][r - 1] + e[r + 1][j] + pl;
                if (t < e[i][j]) {
                    e[i][j] = t;
                    roo[i][j] = r;
                }
            }
        }
    }
    cout << e[1][n] << endl;
    ql.push(1);
    qr.push(n);
    while (!ql.empty()) {
        tl = ql.front(); ql.pop();
        tr = qr.front(); qr.pop();
        if (tl >= tr) continue;
        r = roo[tl][tr];
        printf("%d %d %d\n", tl, tr, r);

        ql.push(tl);
        qr.push(r - 1);
        ql.push(r + 1);
        qr.push(tr);
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%3d ", e[i][j]);
        }
        puts("");
    }
    return 0;
}
