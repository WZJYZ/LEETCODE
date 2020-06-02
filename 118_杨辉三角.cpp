//
// Created by lwj on 2020/6/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //递归
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 1; i <= numRows; ++i) {
            tmp.clear(); //清空数据
            for (int j = 1; j <= i ; ++j) {
                tmp.push_back(helper(i, j));
            }
            res.push_back(tmp);
        }

        return res;
    }

    int helper(int i, int j) {
        if (j == 1 || i == j) {
            return 1;
        }

        return helper(i-1, j-1) + helper(i-1, j);
    }
};

class Solution2 {
public:
    //动态规划
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 1; i <= numRows; ++i) {
            vector<int> tmp;

            for (int j = 1; j <= i; ++j) {
                if (j == 1 || j == i) {
                    tmp.push_back(1);
                }else {
                    tmp.push_back(res[i-2][j-2] + res[i-2][j-1]); //注意坐标
                }
            }
            res.push_back(tmp);
        }

        return res;
    }


};

int main() {
    Solution2().generate(5);
}