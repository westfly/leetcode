#include "code_utils.h"

int twoSum(vector<int>& nums, int povit, int begin, int end, int target) {
    int res = INT_MIN;

    while (begin < end) {
        int curr_sum = nums[begin] + nums[end] + nums[povit];
        printf("twoSum %d\t%d\t%d = %d\t%d\n", povit, begin, end, curr_sum, target);
        if (curr_sum < target) {
            ++begin;
        } else if (curr_sum > target){
            --end;
        } else {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   povit, nums[povit], begin, nums[begin], end, nums[end]);    
            --end;
            ++begin;
            res = target;
            break;
        }
        printf("%d\t%u\n", abs(curr_sum - target),abs(res - target));
        if (abs(curr_sum - target) < abs(res - target)) {
            printf("exchange %d\n", curr_sum);
            res = curr_sum;
        }
    }
    return res;
}
int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    print_array(nums);
    int curr = INT_MIN;
    int len = nums.size();
    for (int i = 0; i < len - 2; ++i) {
        int next = twoSum(nums, i, i + 1, len - 1, target);
        printf("threeSumClosest:%d\t%d\n", curr, next);
        if (abs(next-target) < abs(curr-target)) {
            curr = next;
        }
    }
        
    return curr;
}


int main(int argc, char *argv[]) {
    vector<int> a;
    //int array [] = {-1,2,1,-4};
    int array [] = {0,1,2};
    generate_array(array, ARRAY_SIZE_UNSAFE(array), &a);

    print_array(a);

    auto z = threeSumClosest(a, 0);
    printf("%d\n", z);
}
