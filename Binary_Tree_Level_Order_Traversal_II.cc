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
        vector<vector<int> > ans;
        vector<int> sum;
    public:
        void search(TreeNode *node, int level) {
            if(node==NULL) return;
            if(ans.size()<=level) {
                ans.push_back(sum);
            }
            ans[level].push_back(node->val);
            search(node->left,level+1);
            search(node->right,level+1);
        }
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            ans.clear();
            sum.clear();
            search(root, 0);
            for(int i=0;i<ans.size()/2;i++) {
                sum=ans[i];
                ans[i]=ans[ans.size()-1-i];
                ans[ans.size()-1-i]=sum;
            }
            return ans;        
        }
};



