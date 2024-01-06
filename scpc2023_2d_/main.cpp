#include <iostream>
#include <cstdio>
#include <cmath>
#define N 3005
using namespace std;

typedef long long ll;
ll T, tc, ans, n, k, kk, qi, M = 4e18, Q, sq, sz, g1, g2, x[N], h[N], gmn[405], smn[405][405], xmn[N][N];
ll imn[N][1300];
ll cal(ll p, ll q) {
    return (x[q] - x[p]) * (h[p] + h[q]);
}

ll f(ll x, ll p, ll q) {
    ll re = M;
    while (p < q) {
        if ((p&1)) re = min(re, imn[x][p++]);
        if (!(q&1)) re = min(re, imn[x][q--]);
        p >>= 1;
        q >>= 1;
    }
    if (p == q) re = min(re, imn[x][p]);
    return re;
}

int main()
{
    ll i, j, w, u, t, st, en, cu1, cu2, eni, enj;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%lld", &n);
        for (i =1; i <=n; i++) {
            scanf("%lld %lld", &x[i], &h[i]);
        }
        sq = sqrt(n);
        sz = n / sq;
        for (i = 0; i <= sz; i++) {
            en = min((i + 1) * sq - 1, n);
            gmn[i] = M;
            for (j = i * sq; j <= en; j++) {
                for (w = j + 1; w <= en; w++) {
                    gmn[i] = min(gmn[i], cal(j, w));
                }
            }
        }
//        for (kk = 1; kk < (sz + 1); kk *= 2);
//        for (i = 1; i <= n; i++) {
//            for (j = 1; j <= kk * 2; j++) imn[i][j] = M;
//        }
        for (i = 0; i <= sz; i++) {
            smn[i][i] = M;
            eni = min((i + 1) * sq - 1, n);
            for (j = i + 1; j <= sz; j++) {
                smn[i][j] = smn[i][j - 1];
                enj = min((j + 1) * sq - 1, n);
                for (w = i * sq; w <= eni; w++) {
                    for (u = j * sq; u <= enj; u++) {
                        t = cal(w, u);
                        smn[i][j] = min(smn[i][j], t);
//                        imn[w][kk + j] = min(imn[w][kk + j], t);
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            xmn[i][i] = M;
            for (j = i + 1; j <= n; j++) {
                xmn[i][j] = min(xmn[i][j - 1], cal(i, j));
            }
        }
//        for (i = 1; i <= n; i++) {
//            for (j = kk - 1; j >= 1; j--) imn[i][j] = min(imn[i][j * 2], imn[i][j * 2 + 1]);
//        }
        scanf("%lld", &Q);
        printf("Case #%lld\n", tc);
        for (qi = 1; qi <= Q; qi++) {
            scanf("%lld %lld", &st, &en);
            g1 = st / sq;
            g2 = en / sq;
            ans = M;
            if (g2 - g1 <= 1) {
                for (i = st; i <= en; i++) {
                    ans = min(ans, xmn[i][en]);
                }
            } else {
                ans = min(ans, smn[g1 + 1][g2 - 1]);
                for (i = g1 + 1; i < g2; i++) ans = min(ans, gmn[i]);
//                cu1 = min((g1 + 1) * sq - 1, n);
//                for (i = st; i <= cu1; i++) {
//                    ans = min(ans, f(i, kk + g1 + 1, kk + g2 - 1));
//                }
//                cu2 = max(1ll, g2 * sq);
//                for (i = cu2; i <= en; i++) {
//                    ans = min(ans, f(i, kk + g1 + 1, kk + g2 - 1));
//                }
                for (i = st; i <= en; i++) {
                    ans = min(ans, xmn[i][en]);
                }
            }
            printf("%lld\n", ans);
        }

    }
    return 0;
}

