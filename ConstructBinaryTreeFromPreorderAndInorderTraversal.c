// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
                           int inorderSize) {
    if (preorderSize <= 0 || inorderSize <= 0 || preorder == NULL ||
        inorder == NULL)
        return NULL;
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    n->val = preorder[0];
    int pviot = 0;
    for (; pviot < inorderSize && inorder[pviot] != n->val; pviot++)
        ;
    n->left = buildTree(preorder + 1, pviot, inorder, pviot);
    n->right = buildTree(preorder + pviot + 1, preorderSize - pviot - 1,
                         inorder + pviot + 1, inorderSize - pviot - 1);
    return n;
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public
class Solution {
public
    TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeIter(preorder, 0, preorder.length, inorder, 0,
                             inorder.length);
    }
public
    TreeNode buildTreeIter(int[] preorder, int pbegin, int pend, int[] inorder,
                           int ibegin, int iend) {
        if (pbegin >= pend)
            return null;
        TreeNode n = new TreeNode(preorder[pbegin]);
        int pviot = ibegin;
        for (; pviot < iend && inorder[pviot] != preorder[pbegin]; pviot++)
            ;
        n.left =
            buildTreeIter(preorder, pbegin + 1, pbegin + 1 + pviot - ibegin,
                          inorder, ibegin, pviot);
        n.right = buildTreeIter(preorder, pbegin + 1 + pviot - ibegin, pend,
                                inorder, pviot + 1, iend);
        return n;
    }
}
