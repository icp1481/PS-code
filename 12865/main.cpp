#include <iostream>
#include <cstdio>
#define N 100005
using namespace std;

int n, m, ans, a[N];
int main()
{
    int i, j, t1,t2;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >>n >> m;

    for (i = 0; i < n; i++) {
        cin >> t1 >> t2;
        for (j = m; j >= t1; j--) {
            a[j] = max(a[j], a[j - t1] + t2);
        }
    }
    for (j = 1; j <= m; j++) ans = max(ans, a[j]);
    cout << ans;
    return 0;
}
