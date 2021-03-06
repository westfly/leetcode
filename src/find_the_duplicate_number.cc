#include "code_utils.h"
class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
        int duplicate_num = 0;
        int size = nums.size();
        int index = 0;
        while (index < size) {
            ++index;
            duplicate_num += nums[index] - index;
        }
        return duplicate_num; 
    }
    // 1. 鸽巢原理
    // 2. 空间复杂度为O(1)，则无法用 hashmap
    // 3. 时间复杂度为O(n^2)，无法用 brute force
    int findDuplicate2(vector<int>& nums) {
        int begin = 1;
        int end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin)/2;
            int count = 0;
            for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
                if (*iter < mid) {
                    ++count;
                }
            }
            if (count < mid) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
};
// fast-low pointer
int main(int argc, char *argv[])
{
    return 0;
}
