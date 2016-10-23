#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n)
    {
        ++ count;
        n = (n - 1) & n;
    }
    return count;
}

int main(int argc, char *argv[])
{
    for(int i = 0; i < 16; ++i) {
        printf("%d\t%d\n", i, hammingWeight(i));
    }
    return 0;
}
