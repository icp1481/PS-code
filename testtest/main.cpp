#include <iostream>
#include <cstdio>
using namespace std;

int n, s;
int main()
{
    int i, t;
    freopen ("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> t;
        s += t;
    }
    cout << s;
    return 0;
}
