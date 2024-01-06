#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

typedef long long ll;
ll T, tc, ans, n, k, qi, M = 4e18, Q, x[N], h[N];

ll cal(ll p, ll q) {
    return (x[q] - x[p]) * (h[p] + h[q]);
}

ll f(ll p, ll q) {
    ll i, j, t1, t2, l, r, re, md;
    if (p >= q) return M;
    md = ((p +q) >> 1);
    re = min(f(p, md), f(md + 1, q));
    re = min(re, cal(md, md + 1));
    for (i = md, j = md + 1; ;) {
        for (l = i - 1; l >= p; l--) {
            if (h[l] < h[i]) break;
        }
        for (r = j + 1; r <= q; r++) {
            if (h[r] < h[j]) break;
        }
        if (l < p && r > q) break;
        if (l >= p) t1 = cal(l, j);
        else t1 = M;
        if (r <= q) t2 = cal(i, r);
        else t2 = M;
        if (t1 < t2) {
            re = min(re, t1);
            i = l;
        } else {
            re = min(re, t2);
            j = r;
        }
    }
    return re;
}

int main()
{
    ll i, st, en;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%lld", &n);
        for (i =1; i <=n; i++) {
            scanf("%lld %lld", &x[i], &h[i]);
        }
        scanf("%lld", &Q);
        printf("Case #%lld\n", tc);
        for (qi = 1; qi <= Q; qi++) {
            scanf("%lld %lld", &st, &en);
            ans = f(st, en + 1);
            printf("%lld\n", ans);
        }

    }
    return 0;
}

