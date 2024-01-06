#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 5005
using namespace std;

typedef long long ll;
ll n, m, T, M = 9e18, mn1, mn2, d[2][N], x[N][N], y[N][N];
vector<ll> a, b;
int main()
{
    string st;
    ll i, j, t1, t2;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> T;
    a.push_back(-1); b.push_back(-1);
    for (i = 1; i <= n; i++) {
        cin >> st >> t2;
        if (st[0] == 'A') a.push_back(t2);
        else b.push_back(t2);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    x[0][0] = y[0][0] = -1;
    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < b.size(); j++) {
            if (i == 0 && j == 0) continue;
            t1 = t2 = M;
            if (i > 0) {
                mn1 = (x[i - 1][j] == -1 ? 0 : x[i - 1][j]);
                mn1 = max(mn1, (y[i - 1][j] == -1 ? 0ll : y[i - 1][j] + T));
                mn1 = max(mn1, a[i]);
                t1 = d[(i - 1) % 2][j] + mn1 - a[i];
            }
            if (j > 0) {
                mn2 = (y[i][j - 1] == -1 ? 0 : y[i][j - 1]);
                mn2 = max(mn2, (x[i][j - 1] == -1 ? 0ll : x[i][j - 1] + T));
                mn2 = max(mn2, b[j]);
                t2 = d[i % 2][j - 1] + mn2 - b[j];
            }
//            printf("%lld %lld %lld %lld %lld %lld\n", i, j, t1, t2, mn1, mn2);
            if (t1 <= t2) {
                d[i % 2][j] = t1;
                x[i][j] = mn1;
                y[i][j] = y[i - 1][j];
            } else {
                d[i % 2][j] = t2;
                y[i][j] = mn2;
                x[i][j] = x[i][j - 1];
            }
        }
    }
    cout << d[(a.size() - 1) % 2][b.size() - 1];
    return 0;
}
