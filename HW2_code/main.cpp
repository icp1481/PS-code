#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

typedef long long ll;
ll n, NN, N, pp, s;
ll b[10] = {0, 1, 0, 0, 1, 0, 1, 0};
ll fa[10] = {0, 1, 0, 2, 1, 0, 4, 0}; // H�� 0, T�� 1
// ������ ��ġ���� �������� ��, ��� ��ġ�� ���ư��� �ϴ� �� index ǥ��
double pp2;
int main()
{
    ll i, c, t, x, t1, t2;
    double t3;
    freopen("input.txt", "r", stdin);
    srand(time(NULL));
    cin >> pp2;
    cin >> N;
    printf("p= %.1f, N = %d\n", pp2, N);
    pp = pp2 * 100;
    NN = N;
    while (N--) {
        i = 0;
        for (c = 1; ; c++) {
            t = rand() % 100;
            if (t < pp) x = 0;
            else x = 1;
            if (x == b[i]) i++;
            else i = fa[i];
            if (i == 8) break;
        }
        s += c;
    }
    printf("��� Ƚ��: %.9f", (double)s / NN);
    return 0;
}
