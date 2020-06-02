//
// Created by lwj on 2020/5/12.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool isValid(vector<vector<char>>& grid, int i, int j) {

        return i >=0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;

        int n = grid[0].size();
        if (n == 0)
            return 0;


        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;
        que.push({i, j});

        while (!que.empty()) {
            pair<int, int> tmp = que.front();
            que.pop();
            int r = tmp.first;
            int c = tmp.second;
            grid[r][c] = '0';
            for (int k = 0; k < dir.size(); ++k) {
                int x = r + dir[k][0];
                int y = c + dir[k][1];

                if (isValid(grid, x, y) && grid[x][y] == '1') {
                    grid[x][y] = '0';
                    que.push({x, y});
                }
            }

        }
    }

};

int main() {
    vector<vector<char>> grid1 = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    cout << Solution().numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    cout << Solution().numIslands(grid2) << endl;
    vector<vector<char>> grid3;
    cout << Solution().numIslands(grid3) << endl;
    return 0;
}