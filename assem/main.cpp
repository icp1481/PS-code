#include <iostream>
#include <cstdio>
using namespace std;

// Function to multiply two matrices
void multiply(int a[], int b[]) {
    int x = a[0] * b[0] + a[1] * b[2];
    int y = a[0] * b[1] + a[1] * b[3];
    int z = a[2] * b[0] + a[3] * b[2];
    int w = a[2] * b[1] + a[3] * b[3];
    a[0] = x;
    a[1] = y;
    a[2] = z;
    a[3] = w;
}
// Function to raise a matrix to the power of n
void matrixPower(int mat[], int n) {
    int i = 0;
    int temp[4];
    if (n <= 1) return;
    for(i=0; i<4; i++)
    temp[i] = mat[i];
//    printf("%d \n", n);
//    for (i = 0; i < 4; i++) printf("%d ", mat[i]);
//    puts("");
    matrixPower(mat, n / 2);
    multiply(mat, mat);

////    printf("%d \n", n);
////    for (i = 0; i < 4; i++) printf("%d ", mat[i]);
////    puts("");
    if (n % 2 == 1) {
        multiply(mat, temp);
    }
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int mat[4];
    mat[0] = 1;
    mat[1] = 1;
    mat[2] = 1;
    mat[3] = 0;
    matrixPower(mat, n - 1);
    return mat[0];
}
int main()
{
    long long n, i, a[50];
    cin >>n;

    a[1] = 1;
    a[2] = 1;
    for (i = 3; i <= 46; i++) a[i] = a[i - 1] + a[i - 2];
    for (i = 3; i <= 46; i++) printf("%lld %lld\n", i, a[i]);
    return 0;
}
