#include "code_utils.h"

vector<vector<int>> twoSum(vector<int>& nums, int povit, int begin, int end, int sum) {
    vector<vector<int>> res;
    while (begin < end) {
        int curr = nums[begin] + nums[end];
        if (curr < sum) {
            ++begin;
        } else if (curr > sum){
            --end;
        } else {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   povit, nums[povit], begin, nums[begin], end, nums[end]);
            res.push_back({nums[povit], nums[begin],nums[end]});
            --end;
            ++begin;
            while (begin < end && nums[begin] == nums[begin - 1])  
                ++begin;
            while (begin < end && nums[end] == nums[end + 1])  
                --end;  

        }
    }
    return res;
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    // 边界
    if (nums.size() < 3) {
        return res;
    }
    sort(nums.begin(), nums.end());
    print_array(nums);
    int len = nums.size();
    for (int i = 0; i < len - 2; ++i) {
        auto x = twoSum(nums, i, i + 1, nums.size() -1 , -nums[i]);
        copy(x.begin(), x.end(), back_insert_iterator<decltype(res)>(res));
        while (i < len - 2 && nums[i] == nums[i + 1])
            ++i;
    }
    return res;
}


int main(int argc, char *argv[]) {
    vector<int> a;
    int array [] = {-1, 0, 1, 2, -1, -4};
    generate_array(array, ARRAY_SIZE_UNSAFE(array), &a);

    print_array(a);

    auto res = threeSum(a);
    for (auto & i : res) {
        print_array(i);
    }

}
