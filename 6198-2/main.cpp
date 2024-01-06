#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll n, h, ans;
stack<ll> s;
int main() {
    ll i;
    freopen ("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		ans += s.size();
		s.push(h);
	}
	printf("%lld", ans);
	return 0;
}
