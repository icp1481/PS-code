#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, s, w, L, cnt;
queue<int> qw, qt;
int main()
{
    int i, t, tw, tt;
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> L;
    tt = 0;
    for (i = 0; i < n; i++) {
        cin >> t;
        while (!qw.empty() && (s + t > L || cnt >= w)) {
            tw = qw.front(); qw.pop();
            tt = qt.front(); qt.pop();
            s -= tw;
            cnt--;
        }
        qw.push(t);
        qt.push(tt + w);
        cnt++;
        s += t;
        tt += 1;
    }
    while (!qw.empty()) {
        tw = qw.front(); qw.pop();
        tt = qt.front(); qt.pop();
    }
    cout << tt + 1;
    return 0;
}
