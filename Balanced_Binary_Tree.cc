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
    struct bund {
        bool balance;
        int depth;
        bund() {}
        bund(bool x, int y) {
            balance = x;
            depth = y;
        }
    };
public:
    int max(int x, int y) {
        return x>y?x:y;
    }
    bund SBT(TreeNode *node) {
        if(node==NULL) return bund(1,0);
        bund lb = SBT(node->left);
        bund rb = SBT(node->right);
        if(lb.balance == 0 || rb.balance ==0 ) return bund(0, max(lb.depth,rb.depth)+1);
        else {
            if(lb.depth-rb.depth>=2 || lb.depth-rb.depth<=-2) return bund(0, max(lb.depth,rb.depth)+1);
            else return bund(1, max(lb.depth,rb.depth)+1);
        }
    }
    bool isBalanced(TreeNode *root) {
        bund bb = SBT(root);
        return bb.balance;
    }
};
