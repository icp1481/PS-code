#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 100005
using namespace std;

int n, m, C, cnt[N], mx[N], ans[N], cu[N];
vector<int> a[N], b[N];
struct str {
    int z, ti, po;
};

bool operator < (str p, str q) {
    return p.ti > q.ti;
}

priority_queue<str> qu;

void pu(int p, int q) {
    cnt[p]--;
    mx[p] = max(mx[p], q);
    if (cnt[p] == 0) qu.push({1, mx[p], p});
}

int main()
{
    int i, t1, t2, t3;
    str t;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> C;
    for (i = 1; i <= n; i++) {
        cin >> cu[i];
        qu.push({0, cu[i], i});
        cnt[i] = 1;
    }

    for (i = 0; i < C; i++) {
        cin >> t1 >> t2 >> t3;
        a[t1].push_back(t2);
        b[t1].push_back(t3);
        cnt[t2]++;
    }
    while (!qu.empty()) {
        t = qu.top(); qu.pop();
        if (t.z == 0) {
            cnt[t.po]--;
            mx[t.po] = max(mx[t.po], t.ti);
            if (cnt[t.po] == 0) qu.push({1, mx[t.po], t.po});
        } else {
            ans[t.po] = t.ti;
            for (i = 0; i < a[t.po].size(); i++) {
                pu(a[t.po][i], t.ti + b[t.po][i]);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
