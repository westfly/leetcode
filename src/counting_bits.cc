#include "code_utils.h"
int count_bits_internal(int num, int before)
{
    return before + (num & 1);
}
vector<int> countBits(int num) {
    int n = 0;
    vector<int> res;
    for (int i = 1; i <= num; ++i) {
        res.push_back(n);
        n = count_bits_internal(i, res[i/2]);
    }
    return res;
}
int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    vector<int> res = countBits(n);
    for (auto iter = res.begin(); iter != res.end(); ++iter) {
        printf("%d\t", *iter);
    }
    putchar('\n');
    return 0;
}
