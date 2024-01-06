#include <iostream>
#include <cstdio>
using namespace std;

int n, cnt, a[4] = {3, 2, 0, 2};
int main()
{
    int i, j, w;
    cin >> n;
    for (i = 2023; i <= n; i++) {
        j = i;
        w = 0;
        while (j > 0) {
            if (w < 4 && a[w] == j % 10) w++;
            j /= 10;
        }
        if (w == 4) cnt++;
    }
    cout << cnt;
    return 0;
}
