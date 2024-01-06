#include <iostream>
#include <cstdio>
#include <set>
#define N 200005
using namespace std;

int n, a[N];
set<int> v;
int main()
{
    int i;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        v.insert(a[i]);
    }
    for (i = 0; i <= n; i++) {
        v.lower_bound()
        if (i < n) {
            v.erase(a[i]);
        }
    }
    return 0;
}
