#include "head.h"

/**
 https://leetcode.com/problems/reverse-nodes-in-k-group

 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.

 For example,
   Given this linked list: 1->2->3->4->5
   For k = 2, you should return: 2->1->4->3->5
   For k = 3, you should return: 3->2->1->4->5
 */

// refer to: https://discuss.leetcode.com/topic/25867/c-elegant-and-small
// modified

/**
 * 链表中每k个节点反转一次
 */
/**
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 26ms, beats 27.25%
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* last = head;
    for (int i = 0; i < k; ++i) {
      if (!last) {
        return head;
      }
      last = last->next;
    }
    ListNode* new_head = reverse(head, last);
    head->next = reverseKGroup(last, k);
    return new_head;
  }

private:
  ListNode* reverse(ListNode* first, ListNode* last) {
    ListNode* prev = last;
    while (first != last) {
      ListNode* next = first->next;
      first->next = prev;
      prev = first;
      first = next;
    }
    return prev;
  }
};
