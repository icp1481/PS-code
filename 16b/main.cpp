#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, m, ss, w = 262144, cnt[1000];
double ans;
struct str {
    int br, num, s;
};

queue<str> qu;
int main()
{
    str t;
    int i, j;
    cin >> n >> m;
    qu.push({0, 1, w});
    while (!qu.empty()) {
        t = qu.front(); qu.pop();
        if (t.br == n) {
            cnt[t.num] += t.s;
            continue;
        }
        if (t.num > m) {
            cnt[t.num] += t.s;
            continue;
        }
        qu.push({t.br + 1, t.num, t.s / 2});
        qu.push({t.br + 1, t.num + 1, t.s / 2});
    }
    ss = 0;
    for (i = 1; i <= m + 1; i++) {
        ss += cnt[i];
    }
    ss = 0;
    for (i = 1; i <= m; i++) {
        ss += cnt[i];
        printf("%d %.9f\n", i, (double)(ss) / w);
    }

    for (i = 1; i <= m; i++) {
        ans += ((double)(cnt[i]) / w) * (m + 1 - i);
    }
    printf("%.9f\n", ans);
    return 0;
}
