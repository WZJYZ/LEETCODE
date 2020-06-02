//
// Created by lwj on 2020/4/25.
//
// 回溯
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;

    bool isValid(vector<string>& board, int row, int col) const {
        int n = board.size();
        // 列冲突
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 右上方冲突
        for (int i=row-1, j=col+1; i>=0 && j < n ; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 左上方冲突
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string>& board, int row) {
        // base case
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        // traverse
        auto n = board[row].size();
        for (auto col = 0; col < n; ++col) {
            // 剪枝， 排除不合法选项
            if (!isValid(board, row, col)) {
                continue;
            }
            // 做选择
            board[row][col] = 'Q';

            backtrack(board, row + 1);

            // 撤销选择
            board[row][col] = '.';
        }
    }
};
