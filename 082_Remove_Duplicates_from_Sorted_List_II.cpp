#include "head.h"

/**
 https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
   Given 1->2->3->3->4->4->5, return 1->2->5.
   Given 1->1->1->2->3, return 2->3.
 */

// refer to:
// modified

/**
 * 有序链表中删除数值出现了多次的节点
 */
/**
 *
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 6ms, beats 54.24%
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    int val = head->val;
    ListNode* p = head->next;
    if (p->val != val) {
      head->next = deleteDuplicates(p);
      return head;
    } else {
      while (p && p->val == val) {
        p = p->next;
      }
      return deleteDuplicates(p);
    }
  }
};
