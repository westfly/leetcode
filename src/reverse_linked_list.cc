#include "code_utils.h"
ListNode* reverse_list_recursively(ListNode* head)
{
  return reverse_slist_recursive(head);
}
ListNode* reverse_list_iteratively(ListNode* head)
{
  return reverse_slist_iterative(head);
}
ListNode* reverseList(ListNode* head)
{
  return reverse_slist(head);
}
int main(int argc, const char *argv[])
{
  ListNode* head = create_slist(10);
  print_slist(head);
  ListNode* new_head = reverseList(head);
  print_slist(new_head);
  destroy_slist(new_head);
  return 0;
}
