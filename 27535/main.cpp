#include <iostream>
#include <cstdio>
#include <algorithm>
#define F first
#define S second
using namespace std;

int n, s, s2, sz, a[9], ans[100];
string ans2, b = "HTCKG";
pair<int, char> c[9];

void f(int p, int q) {
    if (p == 0) ans[sz++] = 0;
    while (p > 0) {
        ans[sz++] = p % q;
        p /= q;
    }
}

int main()
{
    int i, j, t, g;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    for (i = 0; i < 5; i++) {
        cin >> a[i];
        s2 += a[i];
    }
    cin >> n;
    for (i = 0; i < n; i++) {
        s = s2;
        s2 = 0;
        for (j = 0; j < 5; j++) {
            cin >> t;
            a[j] -= t;
            s2 += a[j];
        }
        if (s % 10 < 2) g = 10;
        else g = s % 10;
        sz = 0;
        f(s2, g);
        for (j = sz - 1; j >= 0; j--) printf("%d", ans[j]);
        puts("7H");
        if (s2 == 0) printf("NULL\n");
        else {
            for (j = 0; j < 5; j++) {
                c[j].F = -a[j];
                c[j].S = b[j];
            }
            sort(c, c + 5);
            ans2 = "";
            for (j = 0; j < 5; j++) {
                if (c[j].F == 0) continue;
                ans2 += c[j].S;
            }
            cout << ans2 << endl;
        }
    }
    return 0;
}
