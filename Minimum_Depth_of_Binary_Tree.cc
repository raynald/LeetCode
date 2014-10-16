/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int min(const int x, const int y) {
        return x>y?y:x;
    }
    int depth(TreeNode *node) {
        if(node==NULL) return 200000000;
        if(node->left == NULL && node->right == NULL) return 1;
        return min(depth(node->left),depth(node->right))+1;
    }
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        return depth(root);
    }
};
