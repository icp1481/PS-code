#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 505
using namespace std;

typedef long long ll;
ll T, tc, ans, n, k, m, a[N], a2[505], a1[505];
int main()
{
    ll i;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%lld %lld", &n, &k);
        scanf("%lld", &m);
        for (i =0; i <m; i++) {
            scanf("%lld %lld", &a1[i], &a2[i]);
            a1[i]--;
            a2[i]--;
        }
        if (n <= 8) {
            ans = 0;
            for (i = 0; i < n; i++) a[i] = i + 1;
            do {
                for (i = 0; i < m; i++) {
                    if (a[a1[i]] + a[a2[i]] > k) break;
                }
                if (i == m) ans++;
            } while (next_permutation(a, a + n));
        } else {
            ans = 0;
        }
        printf("Case #%lld\n", tc);
        printf("%lld\n", ans);
    }
    return 0;
}

