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
        int dp1;
        int dp2;
        cmp() {}
        cmp(int x, int y):dp1(x),dp2(y) {}
    };
    int sum;
public:
    int max(int x, int y) {
        return x>y?x:y;
    }
    cmp trav(TreeNode *root) {
        if(root==NULL) return cmp(0,-200000000);
        cmp tmp1 = trav(root->left);
        cmp tmp2 = trav(root->right);
        cmp ans;
        ans.dp1 = max(max(tmp1.dp1, tmp2.dp1),0)+root->val;
        ans.dp2 = max(tmp1.dp1+tmp2.dp1+root->val,max(tmp1.dp2, tmp2.dp2));
        if(ans.dp1>sum) sum = ans.dp1;
        if(ans.dp2>sum) sum = ans.dp2;
        return ans;
    }
    int maxPathSum(TreeNode *root) {
        sum = -200000000;
        cmp tmp = trav(root);
        return sum;
    }
};
