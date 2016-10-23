#include "code_utils.h"
int maxProduct(vector<int>& nums) {
    if (nums.size() <= 0) {
        return 0;
    }
    int min_product = nums[0];
    int max_product = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int a = nums[i] * min_product;
        int b = nums[i] * max_product;
        min_product = std::min(min(a, b), nums[i]);
        max_product = std::max(max(a, b), nums[i]);
        res = max(res, max_product);
    }
    return res;
}
int main(int argc, char *argv[])
{

    return 0;
}
