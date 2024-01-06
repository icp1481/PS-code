#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 2500005
using namespace std;

typedef long long ll;
ll n, B, m, l, r, md1, md2, mn, x, a[N], s[N];
vector<ll> ans;
ll f(ll p) {
    ll i, j, w, re = 0, cnt = 0, cc;
    for (i = p, j = p, w = 0; (i >= 1 || j <= n) && cnt < m; i--, j++, w++) {
        cc = 0;
        if (i >= 1) cc += a[i];
        if (j <= n && i != j) cc += a[j];
        cc = min(cc, m - cnt);
        re += cc * w;
        cnt += cc;
    }
    return re;
}

int main()
{
    ll i, j, w, t1, t2;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> B >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    /*for (i = 1, j = 1; i <= n; i++) {
        for (; j <= n; j++) {
            if (s[j] - s[i - 1] >= m) break;

        }
    }*/
    l = 1;
    r = n +1;
    mn = 2e9;
    while (l < r) {
        md1 = (l * 2 +r) / 3;
        md2 = (l + r *2) / 3;
        t1 = f(md1);
        t2 = f(md2);
        if (t1 < t2) {
            if (t1 < mn) {
                mn = t1;
                x = md1;
            }
            r = md2;
        } else {
            if (t2 < mn) {
                mn = t2;
                x = md2;
            }
            l = md1 + 1;
        }
    }
    /*mn = 2e9;
    for (i = 1; i <= n; i++) {
        t1 = f(i);
        if (t1 < mn) {
            mn = t1;
            x = i;
        }
    }*/
    //cout << mn << " "<< x << endl;
    cout << mn << endl;
    printf("%lld ", x);
    ll cnt = 0, cc;
    for (i = x, j = x; (i >= 1 || j <= n) && cnt < m; i--, j++) {
        cc = 0;
        if (i >= 1) cc += a[i];
        if (j <= n && i != j) cc += a[j];
        cc = min(cc, m - cnt);
        cnt += cc;
        t1 = min(a[i], cc);
        t2 = cc - t1;
        for (w = 0; w < t1; w++) ans.push_back(i);
        for (w = 0; w < t2; w++) ans.push_back(j);
    }
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
    return 0;
}
