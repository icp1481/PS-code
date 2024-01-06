#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

typedef long long ll;
ll T, tc, ans, n, k, ss, a[N], x[33], cnt[33];
ll mo(ll p, ll q) {
    if (p <= 4) {
        return p + q;
    } else if (p == 5) {
        return 20 + q;
    } else if (6 <= p && p <= 9) {
        return p + q;
    } else if (p == 10) {
        if (q == 3) return 23;
        else if (q <= 2) return q + 25;
        else return 24 + q;
    } else if (11 <= p && p <= 15) {
        return p + q;
    } else if (16 <= p && p <= 20) {
        if (p + q > 20) return 0;
        else return p + q;
    } else if (p == 23) {
        if (q <= 2) return p + q + 4;
        else if (q == 3) return 20;
        else return 0;
    }else if (21 <= p && p <= 25) {
        if (p + q > 25) return p + q - 11;
        else return p + q;
    } else if (p == 26 || p == 27){
        if (p + q == 28) return 23;
        else if (p + q <= 27) return p + q;
        else if (p + q <= 30) return p + q - 1;
        else if (p + q == 31) return 20;
        else return 0;
    } else {
        if (p + q < 30) return p + q;
        else if (p + q == 30) return 20;
        else return 0;
    }
}

int main()
{
    ll i, j, po;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%lld %lld", &n, &k);
        for (i =0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (i = 0; i < 30; i++) {
            po = i;
            ss = 0;
            for (j = 0; j < n; j++) {
                po = mo(po, a[j]);
                ss += (po == 0);
            }
            x[i] = po;
            cnt[i] = ss;
        }
        ans = 0;
        po = 0;
        for (i = 0; i < k; i++) {
            ans += cnt[po];
            po = x[po];
        }
        printf("Case #%lld\n", tc);
        printf("%lld\n", ans);
    }
    return 0;
}
