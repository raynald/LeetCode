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
    vector<int> ans;
public:
    void flat(TreeNode *root) {
        if(root == NULL) return;
        ans.push_back(root->val);
        flat(root->left);
        flat(root->right);
    }
    void flatten(TreeNode *root) {
        TreeNode *node;
        ans.clear();
        
        flat(root);
        if(root!=NULL) {
            node = root;
            for(int i=1;i<ans.size();i++) {
                node->left = NULL;
                node->right = new TreeNode(ans[i]);
                node = node -> right;
            }
        }
    }
};
