#include "code_utils.h"
ListNode* reverse_list_kgroup(ListNode* head, ListNode* end, int k) {
  ListNode dummy(0);
  int len = 0;
  dummy.next = head; // init
  ListNode* prev = &dummy;
  while (head != end)
  {
      len = (len + 1)%k;
      ListNode* next = head->next;
      if (0 == len)
      {
          head->next = end; // fake single list
          ListNode* new_tail = prev->next;
          ListNode* new_head = reverse_list_iterative(new_tail, end);
          print_list(new_head, end);
          new_tail->next = next; //relink it
          prev->next = new_head;
          prev = new_tail;
      }
      head = next;
  }
  return dummy.next;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    return reverse_list_kgroup(head, NULL, k);
}
int main(int argc, const char *argv[])
{
    ListNode* head = create_slist(10);
    print_slist(head);
    head = reverseKGroup(head, 3);
    print_slist(head);
    destroy_slist(head);
    return 0;
}
