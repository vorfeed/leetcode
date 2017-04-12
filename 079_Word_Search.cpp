#include "head.h"

/**
 https://leetcode.com/problems/word-search

 Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
 The same letter cell may not be used more than once.

 For example,
 Given board =
 [
   ['A','B','C','E'],
   ['S','F','C','S'],
   ['A','D','E','E']
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 */

// refer to:
// modified

/**
 * 网格中每个节点是一个字符，给定一个字符串，判断能否在网格中找出一个连续的路径为该字符串
 */
/**
 * 回溯法，遍历矩阵中每一个节点作为起点，依次分别向上下左右递归取字符串，判断是否与给定字符串相同
 * 用一个矩阵记录每个节点是否已遍历过，避免重复遍历
 */

// 16ms, beats 81.90%
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    board_ = move(board);
    word_ = word;
    visited_.resize(board_.size(), vector<bool>(board_.front().size(), false));
    for (int row = 0; row < board_.size(); ++row) {
      for (int column = 0; column < board_.front().size(); ++column) {
        if (exist(row, column, 0)) {
          board = move(board_);
          return true;
        }
      }
    }
    board = move(board_);
    return false;
  }

private:
  bool exist(int row, int column, int index) {
    if (index == word_.length()) {
      return true;
    }
    if (row < 0 || column < 0 || row == board_.size()
        || column == board_[row].size() || visited_[row][column]) {
      return false;
    }
    if (board_[row][column] != word_[index]) {
      return false;
    }
    visited_[row][column] = true;
    bool exists = exist(row, column + 1, index + 1)
        || exist(row, column - 1, index + 1)
        || exist(row + 1, column, index + 1)
        || exist(row - 1, column, index + 1);
    visited_[row][column] = false;
    return exists;
  }

  vector<vector<char>> board_;
  vector<vector<bool>> visited_;
  string word_;
};
