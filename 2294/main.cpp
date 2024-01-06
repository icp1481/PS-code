#include <iostream>
#include <cstdio>
#define N 10005
using namespace std;

int M = 1e9;
int n, k, d[N];
int main()
{
	int i, t;
	freopen ("input.txt", "r", stdin);
	cin >> n >> k;
	for (i = 1; i <= k; i++) d[i] = M;
	while (n--) {
		scanf ("%d", &t);
		for (i = 0; i <= k; i++) {
            if (i >= t) d[i] = min(d[i], d[i - t] + 1);
		}
	}
	if (d[k] == M) cout << -1;
    else cout << d[k];
    return 0;
}
