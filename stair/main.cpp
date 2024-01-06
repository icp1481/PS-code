#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    int n;
    freopen("input.txt", "r", stdin);
    cin >> n;
    int steps[20000];
    for(int i = 0; i < n; i++){
        cin >> steps[i+1];
    }
    int score[20000][3];
    score[1][1] = steps[1];
    score[1][2] = steps[1];
    for(int i = 1;i <= n-1; i++){
        score[i+1][2] = score[i][1] +steps[i+1];
        score[i+2][1] = max(score[i][2], score[i][1]) + steps[i+2];
        // cout << i+1 << " " << i <<
    }
    cout << max(score[n][1], score[n][2]);
    return 0;
}
