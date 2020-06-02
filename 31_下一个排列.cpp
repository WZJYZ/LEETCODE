//
// Created by lwj on 2020/4/25.
//

// 算法
/**
1. 从后向前查找第一个相邻升序的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
2. 在 [j,end) 从后向前查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k] 分别就是上文所说的「小数」、「大数」
3. 将 A[i] 与 A[k] 交换
4. 可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
5. 如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int len = nums.size();
        int i = len - 2;
        int j = len - 1;
        int k = len - 1;

        // 1.找到第一个升序
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        // 2.找到A[i] < A[k]
        if (i >= 0) {
            while (nums[k] <= nums[i]) {
                k--;
            }
            // 3. 交换
            swap(nums[i], nums[k]);
        }

        // 4.reverse [j, len)
        for (int m = j, n = len-1; m < n; ++m, --n) {
            int tmp = nums[m];
            nums[m] = nums[n];
            nums[n] = tmp;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution{}.nextPermutation(nums);
}