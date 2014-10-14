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
    bool search(TreeNode *node, int x) {
        if(node==NULL) return false;
        int tmp;
        tmp = x - node->val;
        if(node->left == NULL && node->right == NULL) if (tmp == 0) return true; else return false;
        return search(node->left, tmp) || search(node->right, tmp);
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        return search(root, sum);
    }
};
