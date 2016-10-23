#include "code_utils.h"
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for (int i = 1;i < nums.size(); ++i) {
        res[i] = res[i-1] * nums[i -1];
    }
    long sum = 1;
    for (int i = nums.size() - 1; i>=0; --i) {
        res[i] *= sum;
        sum    *= nums[i];
    }
    return res;
}

int main(int argc, char *argv[])
{
    return 0;
}
