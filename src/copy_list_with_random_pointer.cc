/**
 *  A linked list is given such that each node contains an additional
 *  random pointer which could point to any node in the list or null.
 *  Return a deep copy of the list.
 * */
#include "code_utils.h"
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	return NULL;
}
int main(int argc, char* argv[]) {
	ListNode* h1 = create_slist(10);
	print_slist(h1);
	return 0;
}
