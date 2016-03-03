// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(left != NULL) {
            flatten(left);
            root->left = NULL;
            root->right = left;
            if(right != NULL) {
                flatten(right);
                for(; left->right != NULL; left = left->right) ;
                left->right = right;
            }
        } else {
            flatten(right);
        }
    }
};
