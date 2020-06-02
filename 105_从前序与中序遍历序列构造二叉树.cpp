//
// Created by lwj on 2020/5/22.
//
// Time: o(n)
// Space: o(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    // 中序遍历中元素和索引的映射，空间换时间
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen = preorder.size();
        int inLen = inorder.size();
        for (int i = 0; i < preLen; ++i) {
            index[inorder[i]] = i;
        }

        return helper(preorder, 0, preLen - 1, index, 0, inLen-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int preLeft, int preRight,
            unordered_map<int, int>& index, int inLeft, int inRight) {
        // 递归终止条件
        if (preLeft > preRight || inLeft > inRight) {
            return NULL;
        }

        int rootVal = preorder[preLeft];
        TreeNode* root = new TreeNode(rootVal);
        int pIndex = index[rootVal];

        root->left = helper(preorder, preLeft+1, pIndex-inLeft+preLeft,
                index, inLeft, pIndex-1);
        root->right = helper(preorder, pIndex-inLeft+preLeft+1, preRight,
                index, pIndex+1, inRight);

        return root;
    }
};