//
// Created by lwj on 2020/5/12.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 递归
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }

    void helper(vector<char>& s, int l, int r) {
        if (l >= r)
            return;

        int tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        helper(s, ++l, --r);
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    for(auto c : s) {
        cout << c << " ";
    }
    return 0;
}