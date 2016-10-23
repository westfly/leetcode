#include "code_utils.h"
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0;
		while (m && n) {
				int a = nums1[m- 1];
				int b = nums2[n-1];
        printf("a = %d\tb = %d\n", a ,b);
				if (a <= b) {
						nums1[m + n -1] = b;
						--n;
				} else if (a > b) {
						nums1[m + n -1] = a;
						--m;
				}
				++i;
		}
		while (n >0) {
				nums1[n - 1] = nums2[n - 1];
				--n;
		}
}
int main()
{
  	vector<int> a;
		vector<int> b; 
		generate_array(5, &a);
		sort(a.begin(), a.end());
		generate_array(15, &b);
		sort(b.begin(), b.end());
		a.resize(a.size() + b.size());
    print_array(a);
    print_array(b);
		merge(a, 5, b, b.size());
    print_array(a);
}

