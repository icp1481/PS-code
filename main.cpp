#include <iostream>
#include <cstdio>
#include <cmath>
#define N 505
using namespace std;

typedef long long ll;
ll n, l, r, md, ans, cnt, cnt2;
int main()
{
    ll i, j, t;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    l = 1;
    r = 100000;
    while (l < r) {
        md = (l + r) / 2;
        cnt = md * 4 + 1;
        cnt2 = 0;
        for (i = 1; i < md; i++) {
            t = sqrt((double)(md * md - i * i));
            cnt2 += t;
        }
        cnt += cnt2 * 4;
        if (cnt >= n) ans = r = md;
        else l = md + 1;
    }
    cout << ans;
    return 0;
}
