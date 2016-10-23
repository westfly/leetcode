#include <stdio.h>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return 0 == (n & (n - 1));
}
int main(int argc, char *argv[])
{
    for (int i = 0; i < 16; ++i) {
        printf("%d\t%d\n", i, isPowerOfTwo(i));
    }
    return 0;
}
