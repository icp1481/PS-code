#include <iostream>
#include <cstdio>
using namespace std;

int n, x;
int main()
{
    int i, t1, t2;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> n;
    while (n--) {
        cin >> t1 >> t2;
        x -= t1 * t2;
    }
    if (x == 0) cout << "Yes";
    else cout << "No";
    return 0;
}
