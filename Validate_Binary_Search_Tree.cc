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
    struct cmp {
        int small;
        int big;
        cmp() {}
        cmp(int x, int y): small(x), big(y) {}
    };
public:
    cmp search(TreeNode *root) {
        cmp temp, doub;
        
        doub = cmp(root->val, root->val);
        if(root->left!=NULL) {
            temp = search(root->left);
            if(temp.small>temp.big) return cmp(root->val+1, root->val-1);
            if(temp.big>=root->val) return cmp(root->val+1, root->val-1);
            doub.small = temp.small;
        }
        if(root->right!=NULL) {
            temp = search(root->right);
            if(temp.small>temp.big) return cmp(root->val+1, root->val-1);
            if(temp.small<=root->val) return cmp(root->val+1, root->val-1);
            doub.big = temp.big;
        }
        return doub;
    }

    bool isValidBST(TreeNode *root) {
        cmp temp;
        
        if(root==NULL) return 1;
        if(root->left!=NULL) {
            temp = search(root->left);
            if(temp.small>temp.big) return 0;
            if(temp.big>=root->val) return 0;
        }
        if(root->right!=NULL) {
            temp = search(root->right);
            if(temp.small>temp.big) return 0;
            if(temp.small<=root->val) return 0;
        }
        return 1;
    }
};
