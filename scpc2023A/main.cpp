#include <iostream>
#include <cstdio>
using namespace std;

int T, tc, mx, n, A, B;
int main()
{
    int i, t;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (tc =1; tc <= T; tc++) {
        cin >> n >> A >> B;
        mx = 0;
        for (i = 0; i * A <= n; i++) {
            t = n - i * A;
            if ((t % B) == 0) mx = max(mx, i + t / B);
        }
        printf("Case #%d\n", tc);
        printf("%d\n", mx);
    }
    return 0;
}
