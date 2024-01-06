#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define N 1005
using namespace std;

int n, m, cnt[N], ans[N];
queue<int> q1, q2;
vector<int> a[N];

void pu(int p, int q) {
    if (cnt[p] == 0) {
        q1.push(p);
        q2.push(q);
        ans[p] = q;
    }
}

int main()
{
    int i, j, t, t1, t2;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> t1 >> t2;
        a[t1].push_back(t2);
        cnt[t2]++;
    }
    for (i = 1; i <= n; i++) pu(i, 1);
    while (!q1.empty()) {
        t1 = q1.front(); q1.pop();
        t2 = q2.front(); q2.pop();
        for (i = 0; i < a[t1].size(); i++) {
            t = a[t1][i];
            cnt[t]--;
            pu(t, t2 + 1);
        }
    }
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
