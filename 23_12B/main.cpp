#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define N 200005
using namespace std;

typedef long long ll;
ll h, M = 1e9 + 7;
int n, m, v[N], v2[N], mn[N];

struct str {
    int x, num;
};

bool operator < (str p, str q) {
    return p.num > q.num;
}

priority_queue<str> pq, qu;
vector<int> a[N], b[N];

void pu(int p, int q, int w) {
    if (v2[p] == q || v[p] == q && mn[p] <= w) return;
//    printf("%d %d %d\n", p, q, w);
    v[p] = q;
    mn[p] = w;
    pq.push({p, w});
}

int main()
{
    int i, j, t1, t2;
    str t;
//    freopen ("input.txt", "r", stdin);
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> t1 >> t2;
        a[t1].push_back(t2);
        b[t1].push_back(i);
        a[t2].push_back(t1);
        b[t2].push_back(i);
    }
    for (i = 1; i <= n; i++) {
        pu(i, i, 0);
        h = 0;
        while (!pq.empty()) {
            t = pq.top(); pq.pop();
            if (mn[t.x] < t.num) continue;
            v2[t.x] = i;
//            printf("%d\n", i);
            h = (h * 10 + t.num) % M;
            for (j = 0; j < a[t.x].size(); j++) {
                pu(a[t.x][j], i, b[t.x][j]);
            }
        }
        printf("%lld\n", h);
    }

    return 0;
}
