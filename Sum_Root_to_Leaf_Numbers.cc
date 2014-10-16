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
    int ans;
    
public:
    void search(TreeNode *node, int x) {
        int value;
        value = x * 10 + node -> val; 
        if(node->left == NULL && node->right == NULL) ans += value;
        else {
            if (node->left!=NULL) search(node->left, value);
            if (node->right!=NULL) search(node->right, value);
        }
    }
    int sumNumbers(TreeNode *root) {
        ans = 0;
        if(root==NULL) return 0;
        search(root, 0);
        return ans;
    }
};
