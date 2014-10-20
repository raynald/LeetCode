/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<TreeLinkNode*> > ans;
    vector<TreeLinkNode*> sum;
public:
    void search(TreeLinkNode *node, int level) {
        if(node==NULL) return;
        if(ans.size()<=level) {
            ans.push_back(sum);
        }
        ans[level].push_back(node);
        search(node->left,level+1);
        search(node->right,level+1);
    }
    void connect(TreeLinkNode *root) {
           ans.clear();
           sum.clear();
           search(root, 0);
           for(int i=0;i<ans.size();i++) {
               for(int j=0;j<ans[i].size()-1;j++) {
                   ans[i][j]->next = ans[i][j+1];
               }
               ans[i][ans[i].size()-1]->next = NULL;
           }
    }
};
