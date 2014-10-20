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
    vector<int> pre;
    vector<int> in;
public:
    TreeNode *build(int begin1, int end1, int begin2, int end2) {
        if(begin1>end1) return NULL;
        TreeNode *lnode, *rnode, *node;
        int x = pre[begin1];
        int flag;
        for(int i=begin2;i<=end2;i++)
            if(in[i]==x) {
                flag = i;break;
            }
        lnode = build(begin1+1, begin1+flag-begin2, begin2, flag-1);
        rnode = build(begin1+flag-begin2+1, end1,flag+1, end2);
        node = new TreeNode(x);
        node->left=lnode;
        node->right=rnode;
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        pre = preorder;
        in = inorder;
        return build(0, pre.size()-1, 0, in.size()-1);
    }
};
