#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;

typedef long long ll;
ll n, m, st, en, tc, T, s, ans, a[N], b[N], d[N], qa[N], qb[N], Pi[N], Wi[N];
vector<ll> x;

double cross(ll p, ll q) {
	ll p1 = qa[p], p2 = qa[q], q1 = qb[p], q2 = qb[q];
	return (double)(q2 - q1) / (p1 - p2);
}

void pu(ll p, ll q) {
	qa[en] = p;
	qb[en] = q;
	while (en - st > 1 && cross(en - 2, en - 1) > cross(en - 1, en)) {
		qa[en - 1] = qa[en];
		qb[en - 1] = qb[en];
		en--;
	}
	en++;
}

ll f(ll p) {
	while (st + 1 < en && cross(st, st + 1) < p) {
		st++;
	}
	return qa[st] * p + qb[st];
}

int main()
{
	ll i, j, t, l, r, tr;
	freopen ("input.txt", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (tc =1; tc <= T; tc++) {
        cin >> n;
        s = 0;
        tr = 0;
        x.clear();
        for (i = 0; i < n; i++) {
            cin >> l >>r;
            s += r - l;
            if (i >0) x.push_back(l - tr);
            tr = r;
        }
        sort(x.begin(), x.end());
        st = en = 0;
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> Pi[i];
        }
        for (i = 0; i < m; i++) {
            cin >> Wi[i];
        }
        for (i = 0; i < m; i++) {
            pu(Pi[i], Wi[i]);
        }
        ans = s * Pi[0];
        for (i = 0; i < x.size(); i++) {
            ans += f(x[i]);
        }
        printf("Case #%lld\n", tc);
        printf("%lld\n", ans);
    }
    return 0;
}
