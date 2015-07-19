#include "code_utils.h"

ListNode* remove_list_elements(ListNode* head, ListNode* end, int val)
{
  ListNode dummy(0);
  ListNode* tail = &dummy;
  while (head != end)
  {
      ListNode* next = head->next;
      if (head->val == val)
      {
          dealloc_list_node(head);
      }
      else
      {
        tail->next = head;
        tail = head;
      }
      head = next;
  }
  tail->next = end; // must
  return dummy.next;
}
ListNode* removeElements(ListNode* head, int val) {
    return remove_list_elements(head, NULL, val);
}
int main(int argc, const char *argv[])
{
  int array[] = {1, 6};
  // ListNode* head = create_slist(array, ARRAY_SIZE_UNSAFE(array));
  ListNode* head = create_slist(10);
  print_slist(head);
  ListNode* new_head = removeElements(head, 6);
  print_slist(new_head);
  destroy_slist(new_head);
  return 0;
}
