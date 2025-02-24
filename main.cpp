#include <iostream>
#include <cstdio>
using namespace std;

int n, d[4005], a[3];
int main()
{
    int i, j;
    cin >> n >> a[0] >> a[1] >> a[2];
    d[0] = 0;
    for (i = 1; i <= n; i++) {
        d[i] = -1;
        for (j = 0; j < 3; j++) {
            if (i - a[j] >= 0 && d[i - a[j]] != -1) d[i] = max(d[i], d[i - a[j]] + 1);
        }
    }
    cout << d[n];
    return 0;
}
