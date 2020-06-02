//
// Created by lwj on 2020/4/26.
//

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
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }

        int rootNum = count(root, sum); //以自己为开头的路径树
        int leftNum = pathSum(root->left, sum); //以左孩子为开头的路径数
        int rightNum = pathSum(root->right, sum); //以右孩子为开头的路径数
        return rootNum + leftNum + rightNum;
    }

    int count(TreeNode* node, int sum) {
        if (node == NULL) {
            return 0;
        }

        int isMe = (node->val == sum) ? 1 : 0;

        int left = count(node->left, sum - node->val);
        int right = count(node->right, sum - node->val);

        return isMe + left + right;
    }
};