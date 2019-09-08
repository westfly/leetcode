#include <cstdlib>
int rand7() {
    return rand() % 7 +1;
}
int rand10() {
    int n = 41;
    // 代码差不多，但性能为啥差别较大+ rand7()
    while (n > 40) {
        n = 7 * (rand7() - 1) + rand7();
    }
    return n  % 10 + 1;
}

int main() {
    return 0;
}