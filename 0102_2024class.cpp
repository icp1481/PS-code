#include <iostream>
#include <cstdio>
using namespace std;

long long n, i, T, t, a[20];
int main()
{
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (i = 4; i <= 15; i++) a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	cin >> T;
	while (T--) {
		scanf ("%lld", &t);
		printf("%lld\n", a[t]);
	}
    return 0;
}
