//
// Created by lwj on 2020/4/26.
//

class Solution {
public:
    int multiply(int A, int B) {
        if (A == 0 || B == 0) {
            return 0;
        }
        if (B == 1) {
            return A;
        }
        if (B < 0) {
            B = -B;
            return -helper(A, B);
        }
        return helper(A, B);
    }

    int helper(int m, int n) {
        if (n == 1) {
            return m;
        }

        if (n % 2 == 0) {
            return helper(m, n/2) + helper(m, n/2);
        }else{
            return helper(m, n/2) + helper(m, n/2) + m;
        }
    }
};