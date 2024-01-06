#include <iostream>
#include <cstdio>
#define N 105
using namespace std;

int n, m, a[N][N], b[N][N];
int main()
{
    int i, j;
   // freopen ("input.txt", "r", stdin);
    cin >> n >> m;
    for (i = 0; i <n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 0; i <n; i++) {
        for (j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    for (i = 0; i <n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] += b[i][j];
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}
