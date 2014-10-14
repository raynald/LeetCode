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
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> ans;
            if(root==NULL) return ans;
            int tmp;
            TreeNode *top;
            vector<TreeNode *> q;
            q.clear();
            q.push_back(root);
            while(!q.empty()) {
                top = q.back();
                ans.push_back(top->val);
                q.pop_back();
                if(top->right!=NULL) q.push_back(top->right);
                if(top->left!=NULL) q.push_back(top->left);
            }
            return ans;
        }
};
