//
// Created by lwj on 2020/4/25.
//

#include <iostream>
#include <vector>
using namespace std;

//1. 递归
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // base case
        if (nums.empty()) {
            return {};
        }

        // 拿出最后的元素
        int n = nums.back();
        nums.pop_back();
        // 递归
        vector<vector<int>> res = subsets(nums);

        int size = res.size();
        for (int i = 0; i < size; ++i) {
            // 加上之前取出的元素
            res.push_back(res[i]);
            res.back().push_back(n);
        }

        return res;
    }
};

//2. 回溯
class Solution2{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);

        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[start]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution2().subsets(nums);
    return 0;
}