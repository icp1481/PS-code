#include <iostream>
#include <cstdio>
#define SZ 10005
using namespace std;

int N, ans, A[SZ], d[SZ];
struct st {
    int t1, t2;
};

int f_pl(int p, int num) { // index p에서 type이 num일 때 yahtzee가 추가될 수 있는지 판단 --> 조건을 만족하면 1, 아니면 0 반환
    if (num == 5) {
        return (((A[p - 4] == A[p]) + (A[p - 3] == A[p]) + (A[p - 2] == A[p]) + (A[p - 1] == A[p])) == 4);
    } else if (num == 6) {
        return (((A[p - 5] == A[p]) + (A[p - 4] == A[p]) + (A[p - 3] == A[p]) + (A[p - 2] == A[p]) + (A[p - 1] == A[p])) >= 4);
    } else if (num == 7) {
        return ((((A[p - 6] == A[p]) + (A[p - 5] == A[p]) + (A[p - 4] == A[p]) + (A[p - 3] == A[p]) + (A[p - 2] == A[p])) >= 3)
                && (A[p - 1] == A[p]));
    } else if (num == 8) {
        return ((((A[p - 7] == A[p]) + (A[p - 6] == A[p]) + (A[p - 5] == A[p]) + (A[p - 4] == A[p]) + (A[p - 3] == A[p])) >= 2)
                && (A[p - 2] == A[p]) && (A[p - 1] == A[p]));
    } else if (num == 9) {
        return ((((A[p - 8] == A[p]) + (A[p - 7] == A[p]) + (A[p - 6] == A[p]) + (A[p - 5] == A[p]) + (A[p - 4] == A[p])) >= 1)
                && (A[p - 3] == A[p]) && (A[p - 2] == A[p]) && (A[p - 1] == A[p]));
    }
}

int main()
{
    int i;
    st t;

    cin >> N; // 입력
    for (i = 1; i <= N; i++) scanf("%d", &A[i]);
    // base condition
    d[0] = d[1] = d[2] = d[3] = d[4] = 0;
    cout <<
    for (i = 5; i <= N; i++) {
        // recurrence relation
        d[i] = d[i - 5] + f_pl(i, 5);
        if (i >= 6) d[i] = max(d[i], d[i - 6] + f_pl(i, 6));
        if (i >= 7) d[i] = max(d[i], d[i - 7] + f_pl(i, 7));
        if (i >= 8) d[i] = max(d[i], d[i - 8] + f_pl(i, 8));
        if (i >= 9) d[i] = max(d[i], d[i - 9] + f_pl(i, 9));
    }
    // 최종 답 구하기
    for (i = 5; i <= N; i++) ans = max(ans, d[i]);
    cout << ans;
    return 0;
}
