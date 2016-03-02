// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        bool flag = true;
        vector<int> ret;
        stack<pair<struct TreeNode *, bool>> node_stack;
        while(root) {
            ret.push_back(root->val);
            if(flag == false || (root->right == NULL && root->left == NULL)) {
                if(node_stack.empty()) {
                    break;
                } else {
                    auto node = node_stack.top();
                    node_stack.pop();
                    flag = node.second;
                    root = node.first;
                }
            } else {
                if(root->left == NULL) {
                    root = root->right;
                } else {
                    if(root->right != NULL) {
                        node_stack.push(make_pair(root->right, true));
                    }
                    root = root->left;
                }
            }
        }
        return ret;
    }
};
