#include "code_utils.h"
/*
 * 1. �ѵ�˼�루���ȶ��У�
 * 2. ��������ȡ��k��
 * 3. ����������뷨
   ���֮���϶��н��
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
