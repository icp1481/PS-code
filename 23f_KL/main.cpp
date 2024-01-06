#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

typedef long long ll;
ll n, s, s2, x, L, R, ans, a[N];
vector<ll> al, ar, sz;

ll extended_gcd(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    ll x1, y1;
    ll gcd = extended_gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// (x, y)를 찾는 함수
ll find_xy(ll A, ll l, ll r) {

    ll x_prime, y_prime, tx, ty, mok;
    extended_gcd(l, r, &x_prime, &y_prime);

    tx = x_prime * A;
    ty = y_prime * A;
    if (tx < 0) {
        mok = (-tx) / R;
        if ((-tx) % R) mok++;
        tx += mok * R;
        ty -= mok * L;
    }
    if (ty < 0) {
        mok = (-ty) / L;
        if ((-ty) % L) mok++;
        tx -= mok * R;
        ty += mok * L;
    }
    if (tx >= R) {
        mok = tx / R;
        tx -= mok * R;
        ty += mok * L;
    }
    return tx;
}


int main()
{
    ll i, j;
//    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
//    cin >> n >> L >> R;
//    for (i = 1; i <= n; i++) {
//        cin >> a[i];
//        s += a[i];
//    }
//    for (i = 1, j = n; i <= n;) {
//        if (a[i] == 0) {i++; continue;}
//        while (a[j] == 0 && j > i) {
//            j--;
//        }
//        if (i >= j) break;
//        x = min(a[i], a[j]);
//        al.push_back(i);
//        ar.push_back(j);
//        sz.push_back(x);
//        a[i] -= x;
//        a[j] -= x;
//        s2 += x * 2;
//    }
//    ans = sz.size();
//    if (s2 == s && n * 10 >= ans) {
//        cout << sz.size() << endl;
//        for (i = 0; i < sz.size(); i++) {
//            printf("%lld %lld %lld\n", al[i] - 1, ar[i] - 1, sz[i]);
//        }
//    } else {
//        cout << -1;
//    }
    cin >> L >> R >> x;
    cout << find_xy(x, L, R);
    return 0;
}
