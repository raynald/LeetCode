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
public:
    vector<TreeNode *> generate(int x, int y) {
        TreeNode *root;
        vector<TreeNode *> lft, rgt, ans;
        ans.clear();
        if(x>y) return ans;
        for(int i=x;i<=y;i++) {
            lft = generate(x, i-1);
            rgt = generate(i+1, y);
            if(lft.size()==0) {
                if(rgt.size()==0) {
                    root = new TreeNode(i);
                    ans.push_back(root);
                }
                else 
                for(int j=0;j<rgt.size();j++) {
                    root = new TreeNode(i);
                    root->right = rgt[j];
                    ans.push_back(root);
                }
            }
            else if(rgt.size()==0) {
                for(int j=0;j<lft.size();j++) {
                    root = new TreeNode(i);
                    root->left = lft[j];
                    ans.push_back(root);
                }
            }
            else {
                for(int j=0;j<lft.size();j++) {
                    for(int k=0;k<rgt.size();k++) {
                        root = new TreeNode(i);
                        root->left = lft[j];
                        root->right = rgt[k];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        ans.clear();
        if(n==0) {
            ans.push_back(NULL);
            return ans;
        }
        ans = generate(1, n);
        return ans;
    }
};
