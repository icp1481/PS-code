#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

unsigned bit(unsigned p) {
    unsigned t;
    string ans = "";
cout << p << ": ";
int i;
    for (i = 0; i < 32; i++) {
        if(p%2) ans += '1';
        else ans += '0';
        p /= 2;
    }

    reverse(ans.begin(), ans.end());

    cout << ans[0] << " ";
    for (i = 1; i < ans.size(); i++) {
        if (i % 4 == 1) cout << " ";
        cout <<ans[i];

    }
    cout << endl;
}

void float_add(unsigned x, unsigned y, unsigned *result) {
    //cout << x << endl << y << endl;
    bit(x);
    bit(y);
}

int main()
{
    float f1, f2, result_add;
    scanf("%f %f", &f1, &f2);
    float_add(*(unsigned*)&f1, *(unsigned*)&f2, (unsigned*)&result_add);
    printf("%f\n", f1 + f2);
    return 0;
}
