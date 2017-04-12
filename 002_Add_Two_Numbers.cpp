#include "head.h"

/**
 https://leetcode.com/problems/add-two-numbers

 You are given two linked lists representing two non-negative numbers.
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

// refer to: https://leetcode.com/discuss/18263/sharing-my-line-solution-can-someone-make-even-more-concise
// modified

/**
 * 两个链表形式的数字从低位到高位排列，求这两个数字的和的链表
 */
/**
 * 数字从低位到高位排列，只需直接相加，用一个carry记录进位
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 36ms, beats 32.01%
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode pre_head(0);
    ListNode* p = &pre_head;
    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }
    return pre_head.next;
  }
};
