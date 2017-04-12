#include "head.h"

/**
 https://leetcode.com/problems/remove-duplicates-from-sorted-list

 Given a sorted linked list, delete all duplicates such that each element appear only once.

 For example,
   Given 1->1->2, return 1->2.
   Given 1->1->2->3->3, return 1->2->3.
 */

// refer to:
// modified

/**
 * 链表中删除数值出现了多次的节点（保留一个）
 */
/**
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 9ms, beats 60.52%
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    head->next = deleteDuplicates(head->next);
    return head->val == head->next->val ? head->next : head;
  }
};
