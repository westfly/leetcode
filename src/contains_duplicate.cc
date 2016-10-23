

#include "code_utils.h"
#include <unordered_map>

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> mapping;
    for (int i = 0; i < nums.size(); ++i) {
        if (mapping.find(nums[i]) != mapping.end()) {
            return true;
        }
        mapping[nums[i]] = true;
    }
    return false;
}
int main(int argc, char* argv[]) {

    
}

