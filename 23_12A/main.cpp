#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define N 100005
using namespace std;

int n, s, tc, Q, T, ans, mx[N], v[N], h[N], cnt[N], cnt2[N], bu[N];
string a;
vector<int> b[N], c[N];
queue<int> qu;

void f(int p, int q) {
    int i;
    bu[p] = q;
    h[p] = h[q] + 1;
    cnt[q]++;
    c[p].push_back(q);
    for (i = 0; i < b[p].size(); i++) {
        if (b[p][i] == q) continue;
        f(b[p][i], p);
    }
}

int main()
{
    int i, t, t1, t2;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> a;
    for (i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        b[t1].push_back(t2);
        b[t2].push_back(t1);
    }
    f(1, 0);

    cin >> Q;
    for (tc = 1; tc <= Q; tc++) {
        cin >> T;
        for (i = 1; i <= n; i++) {
            mx[i] = -T -1;
            cnt2[i] = cnt[i];
            if (cnt[i] == 0) {qu.push(i); mx[i] = 0;}
        }
        ans = 0;
        while (!qu.empty()) {
            t = qu.front(); qu.pop();
            if (mx[t] == T) {
                ans++;
                mx[t] = -T - 1;
            }
            for (i = 0; i < c[t].size(); i++) {
                t1 = c[t][i];
                cnt2[t1]--;
                mx[t1] = max(mx[t1], mx[t] + 1);
                if (cnt2[t1] == 0) qu.push(t1);
            }
        }
        ans = max(ans, 1);
        printf("%d\n", ans);
    }
    return 0;
}
