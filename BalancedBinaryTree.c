// https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isBalancedIter(struct TreeNode *root, int *depth) {
    if(root == NULL) {
        return true;
    } else {
        (*depth)++;
    }
    int left_depth = *depth;
    int right_depth = *depth;
    if(isBalancedIter(root->left, &left_depth) && isBalancedIter(root->right, &right_depth)) {
        auto lr = left_depth - right_depth;
        if(lr > 1 || lr < -1) {
            return false;
        } else {
            if(lr == 1) *depth = left_depth;
            else *depth = right_depth;
            return true;
        }
    }
    return false;
}

bool isBalanced(struct TreeNode* root) {
    int depth = 0;
    return isBalancedIter(root, &depth);
}
