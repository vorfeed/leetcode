#include "head.h"

/**
 https://leetcode.com/problems/rotate-list

 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
   Given 1->2->3->4->5->NULL and k = 2,
   return 4->5->1->2->3->NULL.
 */

// refer to:
// modified

/**
 * 链表右旋k个节点
 */
/**
 * 先计算链表总长度，同时找到尾节点
 * 将尾节点指向头节点，将链表组成一个环
 * 从头节点开始往后移总长度-k个节点，将新节点重新设为头节点，断开与前面节点的连接
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 9ms, beats 39.50%
class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
      return nullptr;
    }
    int len = 1;
    ListNode* new_head = head, *tail = head;
    while (tail->next) {
      tail = tail->next;
      ++len;
    }
    tail->next = head;
    if (k %= len) {
      for (int i = 0; i < len - k; ++i) {
        tail = tail->next;
      }
    }
    new_head = tail->next;
    tail->next = nullptr;
    return new_head;
  }
};
