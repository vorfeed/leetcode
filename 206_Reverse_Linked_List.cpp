#include "head.h"

/**
 https://leetcode.com/problems/reverse-linked-list

 Reverse a singly linked list.
 */

// refer to: https://discuss.leetcode.com/topic/17916/8ms-c-iterative-and-recursive-solutions-with-explanations
// modified

/**
 * 单链表倒置
 */
/**
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 9ms, beats 23.29%
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

// 9ms, beats 23.29%
class Solution2 {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* node = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
  }
};
