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
    private:
        vector<vector<int>> x;

    public:
        void search(TreeNode *node, int value, vector<int> &tree) {
            int tmp;

            tree.push_back(node->val);
            tmp = value - node -> val;
            if(node ->left == NULL && node ->right == NULL) {
                if(tmp == 0) x.push_back(tree);
            }
            else {
                if(node->left!=NULL) search(node->left, tmp, tree);
                if(node->right!=NULL) search(node->right, tmp, tree);
            }
            tree.pop_back();
        }
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<int> baum;

            x.clear();
            baum.clear();
            if(root==NULL) return x;
            search(root, sum, baum);
            return x;
        }
};
