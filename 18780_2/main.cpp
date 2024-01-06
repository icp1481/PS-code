#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 100005
using namespace std;

int n, m, C, ti[N], cnt[N];
queue<int> qu;
vector<int> a[N], b[N];

void pu(int p) {
    if (cnt[p] == 0) qu.push(p);
}
int main()
{
    int i, t, t1, t2, t3;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> C;
    for (i = 1; i <= n; i++) cin >> ti[i];
    for (i = 1; i <= C; i++) {
        cin >> t1 >> t2 >> t3;
        a[t1].push_back(t2);
        b[t1].push_back(t3);
        cnt[t2]++;
    }
    for (i = 1; i <= n; i++) {
        pu(i);
    }
    while (!qu.empty()) {
        t = qu.front(); qu.pop();
        for (i = 0; i < a[t].size(); i++) {
            t2 = a[t][i];
            ti[t2] = max(ti[t2], ti[t] + b[t][i]);
            cnt[t2]--;
            pu(t2);
        }
    }
    for (i = 1; i <= n; i++) {
        printf("%d\n", ti[i]);
    }
    return 0;
}
