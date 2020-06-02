//
// Created by lwj on 2020/5/22.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }

    void helper(TreeNode* root) {
        if (root == NULL)
            return;

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
};

class Solution2 {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while ( curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr =curr->left;
            }

            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }


};