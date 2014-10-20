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
    vector<int> post;
    vector<int> in;
public:
    TreeNode *build(int begin1, int end1, int begin2, int end2) {
        if(begin1>end1) return NULL;
        TreeNode *lnode, *rnode, *node;
        int x = post[end2];
        int flag;
        for(int i=end1;i>=begin1;i--)
            if(in[i]==x) {
                flag = i;break;
            }
        lnode = build(begin1, flag-1, begin2, begin2+flag-begin1-1);
        rnode = build(flag+1,end1, begin2+flag-begin1, end2-1);
        node = new TreeNode(x);
        node->left=lnode;
        node->right=rnode;
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        post = postorder;
        in = inorder;
        return build(0, in.size()-1, 0, post.size()-1);        
    }
};

