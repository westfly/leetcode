#include "code_utils.h"
/*
 * 1. 堆的思想（优先队列）
 * 2. 整体排序，取第k个
 * 3. 快速排序的想法
   编程之美上都有解答
 */
#include <queue>
int findKthLargest(vector<int>& nums, int k) {
    std::priority_queue<int> queue;
    for (int i = 0; i < nums.size(); ++i) {
        queue.push(nums[i]);
        if (queue.size() > k) {
            queue.pop();
        }
    }
    return queue.top();
}
int findKthLargestFastSort(vector<int>& nums, int k) {

}
int main(int argc, char *argv[])
{

    return 0;
}
