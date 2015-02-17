#include "code_utils.h"

/* 基本的实现是链表的归并，简单题*/
ListNode *addTwoNumbers(ListNode *h1, ListNode *h2) {
	ListNode dummy(0);
	int carrier = 0;
	ListNode* tail = &dummy;
	while (h1 || h2)
	{
		int sum = 0;
		if (h1) {
			sum += h1->val;
			h1 = h1->next;
		}
		if (h2) {
			sum += h2->val;
			h2 = h2->next;
		}
		sum += carrier;
		carrier = sum / 10;
		sum %= 10;
		ListNode* new_node = alloc_list_node(sum);
		tail->next = new_node;
		tail = new_node;
	}
	tail->next = NULL;
	return dummy.next;
}
int main()
{

	ListNode* h1 = create_slist(9);
	ListNode* h2 = create_slist(4);
	print_slist(h1);
	print_slist(h2);
	ListNode* h3 = addTwoNumbers(h1, h2);
	print_slist(h3);
	destroy_slist(h1);
	destroy_slist(h2);
	destroy_slist(h3);
	return 0;
}
