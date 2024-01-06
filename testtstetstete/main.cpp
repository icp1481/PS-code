#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

typedef long long ll;
const ll M = 1e9 + 7;
ll l2, l3, l5, l7;
ll n, k, kk;
ll a[25];
 ll d[25][2][2], d2[22][58][37][26][22], d3[22][2][58][37][26][22];
//ll d[25][2][2], d2[25][20][20][20][20], d3[25][2][20][20][20][20];
ll pl2[20], pl3[20], pl5[20], pl7[20];
bool v[22][2][2], v2[22][58][37][26][22], v3[22][2][58][37][26][22];
string L, R;

struct str {
    ll id, c1, c2;
};

struct str2 {
    ll id, c2, c3, c5, c7;
};

struct str3 {
    ll id, c, c2, c3, c5, c7;
};

queue<str> qu;
queue<str2> qu2;
queue<str3> qu3;

void pu(str p, ll w) {
    if (!v[p.id][p.c1][p.c2]) {
        d[p.id][p.c1][p.c2] = 0;
        v[p.id][p.c1][p.c2] = 1;
        qu.push(p);
    }
    d[p.id][p.c1][p.c2] = (d[p.id][p.c1][p.c2] + w) % M;
}

void pu2(str2 p, ll w) {
    p.c2 = min(p.c2, l2);
    p.c3 = min(p.c3, l3);
    p.c5 = min(p.c5, l5);
    p.c7 = min(p.c7, l7);
    if (!v2[p.id][p.c2][p.c3][p.c5][p.c7]) {
        d2[p.id][p.c2][p.c3][p.c5][p.c7] = 0;
        v2[p.id][p.c2][p.c3][p.c5][p.c7] = 1;
        qu2.push(p);
    }
    d2[p.id][p.c2][p.c3][p.c5][p.c7] = (d2[p.id][p.c2][p.c3][p.c5][p.c7] + w) % M;
}

void pu3(str3 p, ll w) {
    p.c2 = min(p.c2, l2);
    p.c3 = min(p.c3, l3);
    p.c5 = min(p.c5, l5);
    p.c7 = min(p.c7, l7);
    if (!v3[p.id][p.c][p.c2][p.c3][p.c5][p.c7]) {
        d3[p.id][p.c][p.c2][p.c3][p.c5][p.c7] = 0;
        v3[p.id][p.c][p.c2][p.c3][p.c5][p.c7] = 1;
        qu3.push(p);
    }
    d3[p.id][p.c][p.c2][p.c3][p.c5][p.c7] = (d3[p.id][p.c][p.c2][p.c3][p.c5][p.c7] + w) % M;
}

ll f0(string p) {
    ll x1 = 1, x2 = 1, le = p.size(), i, re = 0, xx;
    str t;
    x1 = x2 = 1;
    for (i = 1; i <= le; i++) {
        a[i] = (p[i - 1] - '0');
    }

//    for (i = 1; i <= le; i++) {
//        cout << a[i];
//    }
//
//    cout << endl;

    for (i = 2; i < le; i++) {
        x1 = (x1 * 10) % M;
        x2 = (x2 * 9) % M;
        xx = (x1 - x2 + M) % M;
        xx = (xx * 9) % M;
        re = (re + xx) % M;
    }

    for (i = 1; i < a[1]; i++) {
        pu({2, 0, 0}, 1);
    }

    pu({2, 1, 0}, 1);

    while (!qu.empty()) {
        t = qu.front(); qu.pop();
//        printf("%lld %1ld %lld\n", t.id, t.c1, t.c2);

        if (t.id >= le + 1) {
            if (t.c2 == 1) re = (re + d[t.id][t.c1][t.c2]) % M;
            continue;
        }

        if (t.c1 == 0) {
            for (i = 0; i <= 9; i++) {
                pu({t.id + 1, 0, (i == 0 || t.c2)}, d[t.id][t.c1][t.c2]);
            }
        } else {
            for (i = 0; i <= a[t.id]; i++) {
                pu({t.id + 1, (i == a[t.id]), (i == 0 || t.c2)}, d[t.id][t.c1][t.c2]);
            }
        }
    }

    return re;
}

ll f1(string p) {
    ll i, re = 0, le = p.size();
    str2 t;
    str3 x;
    for (i = 1; i <= le; i++) {
        a[i] = (p[i - 1] - '0');
    }

    if (le > 1) {
        for (i = 1; i <= 9; i++) {
            pu2({2, pl2[i], pl3[i], pl5[i], pl7[i]}, 1);
        }
        while (!qu2.empty()) {

            t = qu2.front();
            qu2.pop();
//        printf("%lld %lld %lld %lld %lld\n", t.id, t.c2, t.c3, t.c5, t.c7);
            if (t.c2 == l2 && t.c3 == l3 && t.c5 == l5 && t.c7 == l7) re = (re + d2[t.id][t.c2][t.c3][t.c5][t.c7]) % M;

            if (t.id >= le) {
                continue;
            }

            for (i = 1; i <= 9; i++) {
                pu2({t.id + 1, t.c2 + pl2[i], t.c3 + pl3[i], t.c5 + pl5[i], t.c7 + pl7[i]}, d2[t.id][t.c2][t.c3][t.c5][t.c7]);
            }
        }
    }

    for (i = 1; i < a[1]; i++) {
        pu3({2, 0, pl2[i], pl3[i], pl5[i], pl7[i]}, 1);
    }

    pu3({2, 1, pl2[a[1]], pl3[a[1]], pl5[a[1]], pl7[a[1]]}, 1);

    while (!qu3.empty()) {
        x = qu3.front();
        qu3.pop();
//        printf("%lld %lld %lld\n", x.id, x.c, x.c2, x.c3, x.c5, x.c7);

        if (x.id >= le + 1) {
            if (x.c2 == l2 && x.c3 == l3 && x.c5 == l5 && x.c7 == l7) re = (re + d3[x.id][x.c][x.c2][x.c3][x.c5][x.c7]) % M;
            continue;
        }

        if (x.c == 0) {
            for (i = 1; i <= 9; i++) {
                pu3({x.id + 1, 0, x.c2 + pl2[i], x.c3 + pl3[i], x.c5 + pl5[i], x.c7 + pl7[i]}, d3[x.id][x.c][x.c2][x.c3][x.c5][x.c7]);
            }
        } else {
            for (i = 1; i <= a[x.id]; i++) {
                pu3({x.id + 1, (i == a[x.id]), x.c2 + pl2[i], x.c3 + pl3[i], x.c5 + pl5[i], x.c7 + pl7[i]}, d3[x.id][x.c][x.c2][x.c3][x.c5][x.c7]);
            }
        }
    }

    return re;
}

ll f(string p) {
    ll i, re = 0;
//    cout << p << endl;
    re = f0(p);
    if (kk == 1) re = (re + f1(p)) % M;
    return re;
}

int main() {
    ll ans, i;
    freopen("input.txt", "r", stdin);
    cin >> k >> L >> R;
    pl2[2] = pl2[6] = 1;
    pl2[4] = 2;
    pl2[8] = 3;
    pl3[3] = 1;
    pl3[6] = 1;
    pl3[9] = 2;
    pl5[5] = 1;
    pl7[7] = 1;
    kk = k;

    while (kk % 2 == 0) {
        l2++;
        kk /= 2;
    }

    while (kk % 3 == 0) {
        l3++;
        kk /= 3;
    }

    while (kk % 5 == 0) {
        l5++;
        kk /= 5;
    }

    while (kk % 7 == 0) {
        l7++;
        kk /= 7;
    }

//    cout << f(R) << " " << f(L) << endl;
//    cout << L << endl;
    ans = f(R);
    memset(v, 0, sizeof(v));
    memset(v2, 0, sizeof(v2));
    memset(v3, 0, sizeof(v3));

    ans = (ans - f(L) + M) % M;

    ll u = 1;

    for (i = 0; i < L.size(); i++) {
        u = (u * (L[i] - '0')) % k;
    }

    if (u == 0) ans = (ans + 1) % M;
    cout << ans;
    return 0;
}
