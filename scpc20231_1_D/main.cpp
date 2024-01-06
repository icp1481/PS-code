#include <iostream>
#include <cstdio>
#include <cstring>
#define N 300000
using namespace std;

int M = 1e9;
int T, tc, mx, n, m, k, fa[N], d[N];
char a[N], b[N];
int main()
{
    int i, j, t;
    freopen ("input.txt", "r", stdin);
    setbuf(stdout, NULL);
    cin >> T;
    for (tc =1; tc <= T; tc++) {
        scanf("%s", a);
        scanf("%s", b);
        n = strlen(a);
        m = strlen(b);
        memset(d, 0, sizeof(d));
        d[n] = 0;
        for (i = n - 1; i >= 0; i--) {
            d[i] = M;
            for (j = i; j < n && j - i < m; j++) {
                if (a[j] != b[j - i]) break;
                d[i] = min(d[i], d[j + 1] + 1);
            }
        }
        /*k = 0;
        for (i = 1; i < m; i++) {
            while (k > 0 && b[i] != b[k]) {
                k = fa[k - 1];
            }
            if (b[i] == b[k]) {
                fa[i] = ++k;
            }
        }
        for (i = 0; i < m; i++) {
            printf("%d ", fa[i]);
        }
*/

        printf("Case #%d\n", tc);
        if (d[0] == M) d[0] = -1;
        printf("%d\n", d[0]);
    }
    return 0;
}
