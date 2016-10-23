#include "code_utils.h"
// 1. 转换为set来做，复杂度多少？
// 2. 给一个数组建立hashmap，遍历另外一个，在hashmap中查找
// 3. 排序一个数组，遍历一个，再排序数组中有二分查找
// 4. 排序两个数组，用归并的思路来做，注意判断不重复
// 5. 如果取值有限，可以考虑有bitmap来做（类似于转换hash来做，但简单）
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            if (res.empty() || nums1[i] != res.back()) {
                res.push_back(nums1[i]);
            }
            ++i, ++j;
        }
    }
    return res;
}
int main(int argc, char *argv[])
{

    return 0;
}
