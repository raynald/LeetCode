/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
    public:
        TreeNode *buildTree(int left, int right, vector<int> &num) {
            if(left>right) return NULL;
            int mid=(left+right)/2;
            TreeNode *node = new TreeNode(num[mid]);
            TreeNode *links = buildTree(left, mid-1, num);
            TreeNode *rechts = buildTree(mid+1, right, num);
            node->left = links;
            node->right = rechts;
            return node;
        }
        TreeNode *sortedArrayToBST(vector<int> &num) {
            return buildTree(0, num.size()-1, num);
        }
};
