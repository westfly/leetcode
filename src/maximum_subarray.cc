#include "code_utils.h"
#include <climits>
int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int curr_max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        curr_max = std::max(curr_max + nums[i], nums[i]);
        max_sum = std::max(curr_max, max_sum);
        printf("%d\t%d\t%d\n", i, curr_max, max_sum);
    }
    return max_sum;
}
int main(int argc, char *argv[])
{
    int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> a;
    generate_array(array, ARRAY_SIZE_UNSAFE(array), &a);
    print_array(a);
    printf("%d\n", maxSubArray(a));
    return 0;
}
