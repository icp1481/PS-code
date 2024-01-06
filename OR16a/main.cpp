#include <iostream>
#include <cstdio>
using namespace std;

int n, m, ss, w = 262144, d[100][100];
int main()
{
    int i, j;
    cin >> n >> m;
    d[0][0] = w;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            d[i][j] = (d[i - 1][j - 1] + d[i][j - 1]) / 2;
            if (j == n) d[i][j] += d[i - 1][j];
        }
    }
    for (i = 1; i <= m; i++) {
        printf("%d %.9f\n", i, (double)(d[i][n]) / w);
        ss += d[i][n];
    }
    printf("ss %d\n", ss);
    double s = 0;
    for (i = 1; i <= m; i++) {
        s += ((double)(d[i][n]) / w) * (m + 1 - i);
    }
    printf("%.9f\n", s);
    return 0;
}
