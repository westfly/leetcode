#include "code_utils.h"

void delete_list_node(ListNode* node, ListNode* end)
{
    if (!node ||node->next == end)
    {
      return;
    }
    ListNode* next = node->next;
    node->next = next->next;
    node->val = next->val;
    dealloc_list_node(next);
}
void deleteNode(ListNode* node) {
  delete_list_node(node, NULL);
}
int main(int argc, const char *argv[])
{
  ListNode* head = create_slist(10);
  print_slist(head);
  ListNode* mid = get_middle_slist(head);
  deleteNode(mid);
  print_slist(head);
  return 0;
}
