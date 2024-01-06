#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, tc, mx, n, m, szA, szB;
vector<int> a, b;
int main()
{
    int i, j, t;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> n >> m;
        a.clear();
        b.clear();
        for (i = 0; i < n; i++) {
            cin >> t;
            if (t < 0) a.push_back(-t);
            else b.push_back(t);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        mx = 0;
        szA = a.size();
        szB = b.size();
        for (i = szA - 1, j = 0; i >= 0; i--) {
            if (a[i] > m) continue;
            mx = max(mx, i + 1);
            for (; j < szB; j++) {
                if ((a[i]) * 2 + b[j] > m) break;
            }
            mx = max(mx, i + 1 + j);
        }

        for (i = szB - 1, j = 0; i >= 0; i--) {
            if (b[i] > m) continue;
            mx = max(mx, i + 1);
            for (; j < szA; j++) {
                if (b[i] * 2 + a[j] > m) break;
            }
            mx = max(mx, j + i + 1);
        }
        printf("Case #%d\n", tc);
        printf("%d\n", mx);
    }
    return 0;
}
