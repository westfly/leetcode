#include "code_utils.h"
/*
 *  Given a linked list, swap every two adjacent nodes and
 *  return its head.
 *  For example,
 *  Given 1->2->3->4, you should return the list as 2->1->4->3.
 *  Your algorithm should use only constant space.
 *  You may not modify the values in the list,
 *  only nodes itself can be changed.
 * */

ListNode *swapPairs(ListNode *head) {
	// only zero or one node in list
	if (!head || !head->next) {
		return head;
	}
	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;
	while (head && head->next)
	{
		ListNode* curr = head->next;
		ListNode* next = curr->next;
		prev->next = curr;
		curr->next = head;
		head->next = next;
		prev = head;
		head = next;
	}
	return dummy.next;
}
int main(int argc, char* argv[]) {

	if (argc < 2)
	{
		printf("need an interger\n");
		return -1;
	}
	ListNode* h1 = create_slist(atoi(argv[1]));
	print_slist(h1);
	ListNode* h2 = swapPairs(h1);
	print_slist(h2);
	destroy_slist(h2);
	return 0;
}
