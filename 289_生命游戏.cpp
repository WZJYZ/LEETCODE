//
// Created by lwj on 2020/4/25.
//
// 1. 二维数组
// 2. 规则检查，8邻域检查
// 3. 原地更新状态，避免数组copy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int neighbors[3] = {0, -1, 1}; // 用于8邻域遍历

        int row = board.size();
        int col = board[0].size();

        // copy board and no change value
        vector<vector<int>> copyBoard(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                copyBoard[row][col] = board[row][col];
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int liveNeighbors = 0;
                // count live neighbors number
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = row + neighbors[i];
                            int c = col + neighbors[j];

                            if ((r < row && r >=0 ) && (c < col && c >= 0) && (copyBoard[r][c] == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }
                // rule check
                if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    copyBoard[row][col] = 0;
                }
                if (copyBoard[row][col] == 0 && liveNeighbors == 3) {
                    copyBoard[row][col] == 1;
                }
            }
        }






    }
};
