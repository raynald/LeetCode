/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        bool check(TreeNode *left, TreeNode *right) {
            if(left==NULL) if (right==NULL) return 1; else return 0;
            if(right==NULL) return 0;
            if(left->val!=right->val) return 0;
            return check(left->left, right->right) && check(left->right, right->left);
        }

        bool isSymmetric(TreeNode *root) {
            if(root==NULL) return 1;
            return check(root->left, root->right);
        }
};
