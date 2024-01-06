#include <iostream>

using namespace std;

char mhex(int p) {
    if (p < 10) {
        return (char)(p + '0');
    } else {
        return (char)(p - 10 + 'a');
    }
}

int main()
{
    cout << mhex(9);

    return 0;
}
