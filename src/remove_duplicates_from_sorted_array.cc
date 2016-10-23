#include "code_utils.h"
int removeDuplicates(vector<int>& nums) {
    int length = nums.size();
    if (length <=1) {
        return length;
    }
    int j = 0;
    for (int i = 1; i < length; ++i) {
        if (nums[j] != nums[i]) {
            ++j;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}
int main(int argc, char *argv[])
{
    return 0;
}
