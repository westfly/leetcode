#include "code_utils.h"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	/*
	ListNode dummy(0);
	ListNode* tail = &dummy;
	ListNode* curr;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			curr = l1;
			l1 = l1->next;
		} else {
			curr = l2;
			l2 =  l2->next;
		}
		tail->next = curr;
		tail = curr;
	}
	curr = l1 ? l1: l2;
	tail->next = curr;
	return dummy.next;
	*/
	return merge_list(l1, l2);
}
int main()
{
	int array [] = {1,2,3,4,6,8,9};
	int len = ARRAY_SIZE_UNSAFE(array);
	ListNode* h1 = create_slist(array, len);
	print_slist(h1);
	ListNode* h2 = create_slist(array + 3, len - 3);
	print_slist(h2);
	ListNode* h3 = mergeTwoLists(h1, h2);
	print_slist(h3);
	destroy_slist(h3);
	return 0;
}
