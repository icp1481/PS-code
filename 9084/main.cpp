#include <iostream>
#include <cstdio>
#define N 10005
using namespace std;

int T, tc, n, m, ans, a[25], d[N];
int main()
{
    int i, j;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (tc= 1; tc <= T; tc++) {
        cin >> n;
        for (i= 0; i < n; i++) cin >> a[i];
        cin >> m;
//        printf("%d ", m);
        d[0] = 1;
        for (i = 1; i <= m; i++) d[i] = 0;
        for (j = 0; j < n; j++) {
            for (i = a[j]; i <= m; i++) {
                d[i] += d[i - a[j]];
            }
        }
        printf("%d\n", d[m]);
    }
    return 0;
}
