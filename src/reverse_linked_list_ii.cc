#include "code_utils.h"

ListNode* reverse_list_between(ListNode* head, ListNode* end, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* range_head = prev;
    while (m--)
    {
        prev = range_head;
        range_head = range_head->next;
        --n;
    }
    ListNode* range_tail = range_head;
    while (n--)
    {
        range_tail = range_tail->next;
    }
    ListNode* next = range_tail->next;
    // reverse
    range_tail->next = end;
    reverse_list_iterative(range_head, end);
    // print_list(range_tail, end);
    prev->next = range_tail;
    range_head->next = next;
    return dummy.next;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {
  return reverse_list_between(head, NULL, m, n);
}
int main(int argc, const char *argv[])
{
  ListNode* head = create_slist(10);
  print_slist(head);
  ListNode* new_head = reverseBetween(head, 1, 8);
  print_slist(new_head);
  destroy_slist(new_head);
  return 0;
}
