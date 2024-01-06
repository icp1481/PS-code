#include <iostream>
#include <cstdio>
using namespace std;

int n, M, ans = 2e9, l[30], r[30];
string a;
int main()
{
    int i, j, t;
    ios::sync_with_stdio(0); cin.tie(0);
    freopen ("input.txt", "r", stdin);
    cin >> n;
    M = 1e9;
    for (i = 0; i < 26; i++) {
        l[i] = M;
        r[i] = M;
    }
    for (i = 0; i < n; i++) {
        cin >> a;
        for (j = 0; j < a.size(); j++) {
            t = a[j] - 'a';
            if (r[t] != M) {
                ans = min(ans, j + r[t]);
                ans = min(ans, int)a.size() - j - 1 + l[t]);
            }
        }
        for (j = 0; j < a.size(); j++) {
            t = a[j] - 'a';
            l[t] = min(l[t], j);
            r[t] = min(r[t], a.size() - j - 1);
        }
    }
    cout << ans;
    return 0;
}
