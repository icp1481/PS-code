#include <iostream>
#include <cstdio>
#include <stack>
#define N 1000005
using namespace std;

typedef long long ll;
ll T, tc, ans, n, k, s, z;
stack<ll> st, cnt;
char a[N];
void ini() {
    while (!st.empty()) {
        st.pop();
        cnt.pop();
    }
    z = 0;
}

int main()
{
    ll i, t, t2;
    setbuf(stdout, NULL);
    freopen ("input.txt", "r", stdin);
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        scanf("%lld", &n);
        scanf("%s", a);
        s = 0;
        z = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == '(') {
                st.push(1);
                cnt.push(0);
            } else if (a[i] == '{') {
                st.push(2);
                cnt.push(0);
            } else if (a[i] == ')') {
                if (!st.empty()) {
                    t = st.top();
                    if (t != 1) ini();
                    else {
                        st.pop();
                        cnt.pop();
                        if (st.empty()) {z++; s += z;}
                        else {
                            t2 = cnt.top(); cnt.pop();
                            cnt.push(t2 + 1);
                            s += (t2 + 1);
                        }
                    }
                } else {
                    ini();
                }
            } else {
                if (!st.empty()) {
                    t = st.top();
                    if (t != 2) ini();
                    else {
                        st.pop();
                        cnt.pop();
                        if (st.empty()) {z++; s += z;}
                        else {
                            t2 = cnt.top(); cnt.pop();
                            cnt.push(t2 + 1);
                            s += (t2 + 1);
                        }
                    }
                } else {
                    ini();
                }
            }
        }
        ini();
        printf("Case #%lld\n", tc);
        printf("%lld\n", s);
    }
    return 0;
}

