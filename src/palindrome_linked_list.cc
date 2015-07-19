#include "code_utils.h"
/*
 * The idea is not so obvious at first glance.
 * Since you cannot move from a node back to its previous node in a singly linked list,
 * we choose to reverse the right half of the list and then compare it with the left half.
 * */
bool is_palindrome_list(ListNode* head, ListNode* end)
{
    if (!head || head->next == end)
    {
      return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    int i = 0;
    while (fast != end && fast->next != end)
    {
      slow = slow->next;
      fast = fast->next->next;
      ++i;
    }
    ListNode* new_head = NULL;
    if (fast != end)
    {
        // even length
        printf("even_len = %d\n", i);
        new_head = reverse_list_iterative(slow->next, end);
    }
    else
    {
        printf("odd_len = %d\n", i);
        // odd fast->next = end
        new_head = reverse_list_iterative(slow, end);
    }
    // head->next = new_head;
    while (new_head != end)
    {
      if (new_head->val != head->val)
      {
        return false;
      }
      new_head = new_head->next;
      head = head->next;
    }
    return true;
}
bool isPalindrome(ListNode* head)
{
  return is_palindrome_list(head, NULL);
}

int main(int argc, const char *argv[])
{
  int array [] = {1,2,3,1};
  // ListNode* head = create_slist(10);
  ListNode* head = create_slist(array, ARRAY_SIZE_UNSAFE(array));
  print_slist(head);
  printf("%d\n", isPalindrome(head));
  destroy_slist(head);
  return 0;
}
