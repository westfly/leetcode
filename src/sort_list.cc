#include "code_utils.h"
/*
 * Sort a linked list in O(n log n) time using
 * constant space complexity.
 * 对于数组来说，满足时间复杂度必然要求二分。
 * 排序局限于归并排序、快速排序
 * 此处选用归并排序
 * */


ListNode *sortList(ListNode *head) {
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* middle = get_middle_slist(head);
	// printf("find middle %d\n", middle->val);
	ListNode* h2 = middle->next;
	middle->next = NULL;
	head = sortList(head);
	h2 = sortList(h2);
	return merge_list(head, h2);
}
int main(int argc, char* argv[]) {
	ListNode* h1 = create_slist(20);
	print_slist(h1);
	ListNode* h2 = sortList(h1);
	print_slist(h2);
	destroy_slist(h2);
	return 0;
}
