#include "head.h"

/**
 https://leetcode.com/problems/binary-tree-right-side-view

 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 For example:
   Given the following binary tree,
     1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
   You should return [1, 3, 4].
 */

// refer to: https://discuss.leetcode.com/topic/11768/my-simple-accepted-solution-java
// modified

/**
 * 二叉树返回每一层最右边的节点
 */
/**
 * 从右子节点开始遍历，每次新到一个层级表示当前节点为该层最右边的节点
 * 新到层级判断方法为当前深度是否高于上面层级已经统计出的最右节点的个数
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 3ms, beats 22.99%
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    rightSideView(root, 0);
    return result_;
  }

private:
  void rightSideView(TreeNode* node, int depth) {
    if (!node) {
      return;
    }
    if (depth == result_.size()) {
      result_.push_back(node->val);
    }
    rightSideView(node->right, ++depth);
    rightSideView(node->left, depth);
  }

  vector<int> result_;
};
