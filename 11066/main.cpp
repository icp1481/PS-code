#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, T, tc, ans;
priority_queue<int> qu;
int main()
{
    int t1, t2, x, i;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >>T;
    for (tc = 1; tc <= T; tc++) {
        cin >> n;
        while(!qu.empty()) {
            qu.pop();
        }
        for (i = 0; i < n; i++) {
            cin >> t1;
            qu.push(-t1);
        }
        ans = 0;
        for (i = 0; i < n - 1; i++) {
            t1 = qu.top(); qu.pop();
            t2 = qu.top(); qu.pop();
            x = -(t1 + t2);
            ans += (x);
            qu.push(-x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
