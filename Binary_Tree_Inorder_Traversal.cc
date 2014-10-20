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

    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        TreeNode* node;
        
        stack.clear();
        ans.clear();
        if(root==NULL) return ans;
        if(root->right!=NULL) stack.push_back(root->right);
        stack.push_back(root);
        if(root->left!=NULL) stack.push_back(root->left);
        root->left=root->right=NULL;
        while(!stack.empty()) {
            node = stack.back();
            stack.pop_back();
            if(node->left==NULL &&node->right==NULL) {
                ans.push_back(node->val);
            }
            else {
                if(node->right!=NULL) stack.push_back(node->right);
                stack.push_back(node);
                if(node->left!=NULL) stack.push_back(node->left);
                node->left=node->right=NULL;
            }
        }
        return ans;
    }
};
