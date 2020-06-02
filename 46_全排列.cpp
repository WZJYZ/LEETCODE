//
// Created by lwj on 2020/4/25.
//
// 回溯算法的框架结构

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track{};
        backtrack(nums, track);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track) {
        // base case
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        // backtrack framework
        // tree traverse
        for (int i = 0; i < nums.size(); ++i) {

            if (count(track.begin(), track.end(), nums[i]) > 0) {
                continue;
            }

            // 前序遍历
            track.push_back(nums[i]);
            backtrack(nums, track);
            // 后序遍历 撤销操作
            track.pop_back();
        }


    }
};

int main() {
    vector<int> nums{1, 2, 3};
    auto res = Solution{}.permute(nums);

    for (auto e1 : res) {

        for (auto e2 : e1) {
            cout << e2 << " ";
        }
        cout << endl;
    }

    return 0;
}