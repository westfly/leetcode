/* Given a list, rotate the list to the right by k places,
 * where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 * */
#include "code_utils.h"


ListNode *rotateRight(ListNode *head, int k) {
	return head;
}

int main(int argc, char* argv[]) {
	ListNode* h1 = create_slist(10);
	print_slist(h1);
	h1 = reverse_slist(h1);
	ListNode* h2  = rotateRight(h1, 2);
	print_slist(h1);
	destroy_slist(h2);
	return 0;
}
