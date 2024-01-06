#include <iostream>
#include <cstdio>
#include <cstdlib>
#define N 1000005
using namespace std;

int n, ne, a[N], ans[N], bu[N], sz[N];
void f() {
    int p, q, h;
    p = 0;
    q = 1;
    h = 0;
    while (q <= n) {
        if (a[q] == h + 1) {
//                printf("%d\n", p);
            bu[q] = p;
            sz[p]++;
            ans[q] = sz[p];
//            ne++;
            p = q;
            q++;
            h++;
        } else if (a[q] > h + 1) {
            cout << -1;
            exit(0);
        } else {
            p = bu[p];
            h--;
        }
    }
}

int main()
{
    int i;
//    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f();
    for (i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
