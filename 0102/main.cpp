#include <bits/stdc++.h>
# define INT_MAX 20

using namespace std;
typedef long long ll;
ll d[INT_MAX];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
     freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    cout << "start";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){

        d[0] = 1;
        d[1] = 2;
        d[2] = 4;
        int a;
        cin >> a;
        for(int j = 3; j < a; j++){
            d[j] = d[j-1] + d[j-2] + d[j-3];

        }
        cout << d[a - 1] << endl;
    }
    return 0;
}
