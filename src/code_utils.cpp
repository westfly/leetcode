/*
 * code_utils.cpp
 *
 *  Created on: 2015
 *      Author: Ares
 */

#include "code_utils.h"
#include <stdlib.h>
#include <time.h>
#include <random>
void generate_array(int a[],int n)
{
	srand(time(NULL));
	for(int i=0; i<n; i++) {
		a[i] = rand()%n + 1;
	}
}
/*特化版本*/
template<>
void print_array(const int array[], size_t n)
{
	static const int kMaxInLine = 10;
	int count = 0;
	while(count < n) {
		printf("%d\t",array[count]);
		if ((++count%kMaxInLine) == 0) {
			putchar('\n');
		}
	}
	putchar('\n');
}

void generate_array(int n, vector<int>* vt)
{
	int array[n];
	
	generate_array(array, n);
	generate_array(array, n, vt);
}
void generate_array(int array[],int n, std::vector<int>* vt)
{
	vt->clear();
	for(int i = 0; i < n; ++i) {
		vt->push_back(array[i]);
	}
}
ListNode* create_slist(int n)
{
	return create_list(n, 1);
}
ListNode* create_slist(int a[],int n)
{
	return create_list(a, n ,1);

}
void destroy_slist(ListNode* h)
{
	destroy_list(h, NULL);
}
void print_slist(ListNode* h)
{
	print_list(h, NULL);
}
ListNode* get_middle_slist(ListNode* h)
{
	return get_middle_list(h, NULL);
}
ListNode* merge_list_prev(ListNode* h1, ListNode* h2)
{
	ListNode dummy(0);
	dummy.next = h1;
	ListNode* prev = &dummy;
	while (h1 && h2)
	{
		if (h1->val < h2->val)
		{
			prev = h1;
			h1 = h1->next;
		} else {
			prev->next = h2;
			h2 = h2->next;
			prev = prev->next; // prev h2;
			prev->next = h1;
		}
	}
	if (h2)
	{
		prev->next = h2;
	}
	return dummy.next;
}
ListNode* merge_list_tail(ListNode* h1, ListNode* h2)
{
	ListNode dummy(0);
	dummy.next = h1;
	ListNode* tail = &dummy;
	ListNode* curr;
	while (h1 && h2)
	{
		if (h1->val < h2->val)
		{
			curr = h1;
			h1 = h1->next;
		} else {
			curr = h2;
			h2 = h2->next;
		}
		tail->next = curr;
		tail = curr;
	}
	tail->next = h1 ? h1 : h2;
	return dummy.next;
}
ListNode* merge_list(ListNode* h1, ListNode* h2)
{
	int r = rand();
	if (r%2)
	{
		return merge_list_prev(h1, h2);
	} else{
		return merge_list_tail(h1, h2);
	}
}
ListNode* reverse_slist_recursive(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* next = head->next;
	ListNode* new_head = reverse_slist_recursive(next);
	next->next = head;
	head->next = NULL; // 不能少!!!
	return new_head;
}
ListNode* reverse_slist_iterative(ListNode* head)
{
	ListNode dummy(0);
	ListNode* prev = &dummy;
	while (head)
	{
		ListNode* next = head->next;
		head->next = prev->next;
		prev->next = head;
		head = next;
	}
	return dummy.next;
}
ListNode* reverse_slist(ListNode* head)
{
	int r = rand();
	if (r%2)
	{
		return reverse_slist_iterative(head);
	} else{
		return reverse_slist_recursive(head);
	}
}
size_t length_slist(ListNode* h)
{
	return length_list(h, NULL);
}
ListNode* create_sclist(int n)
{
	return create_list(n, 0);
}
ListNode* create_sclist(int a[],int n)
{
	return create_list(a, n ,0);

}
void destroy_sclist(ListNode* h)
{
	destroy_list(h, h);
}
void print_sclist(ListNode* h)
{
	print_list(h, h);
}


ListNode* create_list(int n, int list_type)
{
	int array[n];
	generate_array(array, n);
	return create_list(array, n, list_type);
}
ListNode* create_list(int a[],int n, int list_type)
{
	ListNode dummy(0);
	ListNode* tail = &dummy;
	for(int i = 0;i < n; ++i)
	{
		ListNode* new_node = alloc_list_node(a[i]);
		tail->next = new_node;
		tail  = new_node;
	}
	if (list_type) {
		tail->next = NULL; //marked as single list
	} else {
		tail->next = dummy.next;
	}
	return dummy.next;
}
void destroy_list(ListNode* h, ListNode* end)
{
	while (h != end)
	{
		ListNode* next = h->next;
		dealloc_list_node(h);
		h = next;
	}
}
void print_list(ListNode* h,  ListNode* end)
{
    while(h != end){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}
ListNode* get_middle_list(ListNode* h, ListNode* end)
{
	if (!h || !h->next)
	{
		return h;
	}
	ListNode* slow = h;
	ListNode* fast = h->next;
	while ((fast != end) && (fast->next != end))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
size_t length_list(ListNode* h, ListNode* end)
{
	size_t count = 0;
	while (h != end)
	{
		h = h->next;
		++count;
	}
	return count;

}
