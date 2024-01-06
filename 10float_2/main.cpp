#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
void f(double p) {
    ll t = 1, i = 0;
    while (p > 0 && i < 31) {
        //t = t * 10;
        if (p >= 1) { printf("1"); p-=1; }
        else printf("0");
        p *= 2;
        i++;
    }
    //return t;
}

unsigned roun(unsigned p, unsigned q) {
    unsigned G, R, S;
    if (q == -1) return p;
    G = (p >> (q + 1));
    R = (p >> q);
    S = (p & ((1 << q) - 1));
    p >>= (q + 1);
    if ((R & 1) && ((G) || (S))) p += 1;
    return p;
}

int main()
{
    double t1, t2;
    freopen ("input.txt","r", stdin);
    cin >> t1 >> t2;
    f(t1);
    puts("");
    f(t2);
    puts("");
    printf("%u", roun(14223, 0));
    return 0;
}
