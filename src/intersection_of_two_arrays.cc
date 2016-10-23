#include "code_utils.h"
// 1. ת��Ϊset���������Ӷȶ��٣�
// 2. ��һ�����齨��hashmap����������һ������hashmap�в���
// 3. ����һ�����飬����һ�����������������ж��ֲ���
// 4. �����������飬�ù鲢��˼·������ע���жϲ��ظ�
// 5. ���ȡֵ���ޣ����Կ�����bitmap������������ת��hash���������򵥣�
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
