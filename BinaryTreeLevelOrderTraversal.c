// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        function<void(TreeNode *, int)> f;
        f = [&ret, &f](TreeNode *root, int depth){
            if(root == NULL) return;
            if(ret.size() < depth + 1) {
                ret.resize(depth + 1);
            }
            ret[depth].push_back(root->val);
            if(root->left != NULL) f(root->left, depth + 1);
            if(root->right != NULL) f(root->right, depth + 1);
        };
        f(root, 0);
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        stack<TreeNode *> nodes;
        stack<TreeNode *> next_nodes;
        int depth = 0;
        if(root != NULL) {
            nodes.push(root);
            while(!nodes.empty() || !next_nodes.empty()) {
                depth++;
                ret.resize(depth);
                while(!nodes.empty()) {
                    auto n = nodes.top();
                    nodes.pop();
                    ret[depth - 1].push_back(n->val);
                    if(n->left) next_nodes.push(n->left);
                    if(n->right) next_nodes.push(n->right);
                }
                while(!next_nodes.empty()) {
                    nodes.push(next_nodes.top());
                    next_nodes.pop();
                }
            }
        }
        return ret;
    }
};
