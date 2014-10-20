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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int temp;
        ans.clear();
        sum.clear();
        search(root, 0);
        for(int i=1;i<ans.size();i+=2) {
            for(int j=0;j<ans[i].size()/2;j++) {
                temp = ans[i][j];
                ans[i][j]=ans[i][ans[i].size()-1-j];
                ans[i][ans[i].size()-1-j]=temp;
            }
        }
        return ans;      
    }
};

