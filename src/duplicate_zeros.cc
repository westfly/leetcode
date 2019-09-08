#include "code_utils.h"
void duplicateZeros(vector<int>& arr) {
    int count = 0;
    int len = arr.size();
    for (int i = 0;i < len - count - 1; ++i) {
        if (arr[i] == 0) {
            count++;
        }
    }
    arr.resize(len + count);
    for (int i = len - 1; count > 0;--i) {
        int j = i - count;
        printf("%d %d %d\n", i,j , count);
        arr[i] = arr[j];
        if (arr[j] == 0) {
            --count;
            arr[--i] = 0;
        }
        print_array(arr);
    }
    arr.resize(len);
}
int main()
{
    //vector<int> test ={8,5,0,9,0,3,4,7};
    vector<int> test0 = {1,0,2,3,0,4,5,0};
    vector<int> test1 = {0,0,0,0,0,0,0};
    vector<int> test2 = {9,9,9,4,8,0,0,3,7,2,0,0,0,0,9,1,0,0,1,1,0,5,6,3,1,6,0,0,2,3,4,7,0,3,9,3,6,5,8,9,1,1,3,2,0,0,7,3,3,0,5,7,0,8,1,9,6,3,0,8,8,8,8,0,0,5,0,0,0,3,7,7,7,7,5,1,0,0,8,0,0};
    duplicateZeros(test2);
    return 0;
}
[9,9,9,4,8,0,0,3,7,2,0,0,0,0,9,1,0,0,1,1,0,5,6,3,1,6,0,0,2,3,4,7,0,3,9,3,6,5,8,9,1,1,3,2,0,0,7,3,3,0,5,7,0,8,1,9,6,3,0,8,8,8,8,0
[9,9,9,4,8,0,0,0,0,3,7,2,0,0,0,0,0,0,0,0,9,1,0,0,0,0,1,1,0,0,5,6,3,1,6,0,0,0,0,2,3,4,7,0,0,3,9,3,6,5,8,9,1,1,3,2,0,0,0,0,7,3,3,0,0,5,7,0,0,8,1,9,6,3,0,0,8,8,8,8,0]
[9 9 9 4 8 0 0 0 3 7 2 0 0 0 0 0 0 0 0 9 1 0 0 0 0 1 1 0 0 5 6 3 1 6 0 0 0 0 2 3 4 7 0 0 3 9 3 6 5 8 9 1 1 3 2 0 0 0 0 7 3 3 0 0 5 7 0 0 8 1 9 6 3 0 0 8 8 8 8 0 0]