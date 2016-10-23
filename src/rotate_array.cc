#include "code_utils.h"
void rotate(vector<int>& nums, int begin ,int end)
{
    while (begin < end)
    {
        std::iter_swap(nums.begin() + begin, nums.begin() + end);
        ++begin, --end;
    }
}
void rotate(vector<int>& nums, int k) {
    int length = nums.size();
    k %= length;
    rotate(nums, 0, length - 1);
    rotate(nums, 0, k  - 1);
    rotate(nums, k, length - 1);
}
int main(int argc, char *argv[])
{
    vector<int> a;
    generate_array(10, &a);
    print_array(a);
    rotate(a, 3);
    print_array(a);
    return 0;
}
