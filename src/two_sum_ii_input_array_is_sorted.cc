#include "code_utils.h"

vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    vector<int> res;
    while (begin < end) {
        int sum = numbers[begin] + numbers[end];
        if (sum < target) {
                ++begin;
        } else if (sum > target) {
                --end;
        } else {
                res.push_back(begin + 1);
                res.push_back(end + 1);
                ++begin;
                --end;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    return 0;
}
