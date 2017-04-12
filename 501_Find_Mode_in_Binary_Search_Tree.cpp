#include "head.h"

/**
 https://leetcode.com/problems/find-mode-in-binary-search-tree

 Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

 Assume a BST is defined as follows:
   The left subtree of a node contains only nodes with keys less than or equal to the node's key.
   The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
   Both the left and right subtrees must also be binary search trees.

 For example:
   Given BST [1,null,2,2],
     1
       \
         2
       /
     2
   return [2].

 Note: If a tree has more than one mode, you can return them in any order.

 Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
 */

// refer to: https://discuss.leetcode.com/topic/77330/java-4ms-beats-100-extra-o-1-solution-no-map
// modified

/**
 * 二叉查找树中含有重复的数，求出现次数最多的重复，如果多个数字则都输出
 */
/**
 * 先序遍历二叉树，顺序判断先后取到的数是否相同，用计数器记录
 * 遍历时用一个prev变量记录前面遍历到的数的值
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 22ms, beats 35.35%
class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    if (!root) {
      return {};
    }
    traverse(root);
    return { ret_.begin(), ret_.end() };
  }

private:
  void traverse(TreeNode* root) {
    if (!root) {
      return;
    }
    traverse(root->left);
    if (has_prev_) {
      if (root->val == prev_) {
        ++count_;
      } else {
        count_ = 1;
      }
    }
    if (count_ > max_) {
      max_ = count_;
      ret_.clear();
      ret_.emplace(root->val);
    } else if (count_ == max_) {
      ret_.emplace(root->val);
    }
    prev_ = root->val;
    has_prev_ = true;
    traverse(root->right);
  }

  bool has_prev_ { false };
  int prev_ { 0 };
  int count_ { 1 };
  int max_ { 0 };
  unordered_set<int> ret_;
};
