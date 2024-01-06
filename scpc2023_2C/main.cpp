#include <iostream>
#include <cstdio>
#define N 5005
using namespace std;

int T, tc, ans, n, k, m, ti, cnt, la[N], a[N], d[N][N][2], v[N][N][2];
int f(int p, int q, int w) {
    int re = 0, pl, pos, x;
    if (q < 0) return -1e9;
    if (q == 0 || p > n) return 0;
    if (v[p][q][w] == tc) return d[p][q][w];
    v[p][q][w] = tc;
    re = max(re, f(p + 1, q, 1));
    if (a[p] == 1) {
        if (la[p] >= ti * 2 + 1) {
            re = max(re, f(p + ti * 2 + 1, q - 1, 1) + 2 * ti + 1);
        } else {
            if (la[p] <= ti) {
                pos = p + la[p];
                if (la[pos] >= ti + 1) x = pos + ti + 1;
                else x = pos + la[pos];
                re = max(re, f(x, q - 1, (x == pos + ti + 1)) + x - p);
            } else {
                pos = p + la[p];

                if (q >= 2) {
                    pl = pos - p + 1;
                    if (la[pos] >= ti + 1) pl += ti;
                    else pl += (la[pos] - 1);
                    if (la[pos] >= ti + 1) re = max(re, f(pos + ti + 1, q - 2, 1) + pl);
                    else re = max(re, f(pos + la[pos], q - 2, 0) + pl);
                }
                re = max(re, f(pos, q - 1, 0) + pos - p);
            }
        }
    } else {
        if (w == 0) {
            if (la[p] >= ti * 2 + 1) {
                re = max(re, f(p + ti * 2 + 1, q - 1, 1) + 2 * ti + 1);
            } else {
                if (la[p] <= ti) {
                    pos = p + la[p];
                    if (la[pos] >= ti + 1) x = pos + ti + 1;
                    else x = pos + la[pos];
                    re = max(re, f(x, q - 1, (x == pos + ti + 1)) + x - p);
                } else {
                    pos = p + la[p];

                    if (q >= 2) {
                        pl = pos - p + 1;
                        if (la[pos] >= ti + 1) pl += ti;
                        else pl += (la[pos] - 1);
                        if (la[pos] >= ti + 1) re = max(re, f(pos + ti + 1, q - 2, 1) + pl);
                        else re = max(re, f(pos + la[pos], q - 2, 0) + pl);
                    }
                    re = max(re, f(pos, q - 1, 0) + pos - p);
                }
            }
        } else {
            if (la[p] >= ti + 1) {

                re = max(re, f(p + ti + 1, q - 1, 1) + ti);
            } else {
                re = max(re, f(p + la[p], q - 1, 0) + la[p]);
            }
        }
    }
    return d[p][q][w] = re;
}

int main()
{
    int i;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%d", &n);
        for (i =1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d %d", &m, &ti);
        cnt = 0;
        la[n + 1] = la[n + 2] = 1;
        for (i = n; i >= 1; i--) {
            cnt++;
            la[i] = cnt;
            if (a[i] == 2) cnt = 0;
        }
        ans = f(1, m, 1);

        printf("Case #%d\n", tc);
        printf("%d\n", ans);
    }
    return 0;
}

