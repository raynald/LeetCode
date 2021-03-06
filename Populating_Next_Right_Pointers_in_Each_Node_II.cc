/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        TreeLinkNode *p = root->next;
        while(p!=NULL) {
            if(p->left!=NULL) {
                p=p->left;
                break;
            }
            if(p->right!=NULL) {
                p=p->right;
                break;
            }
            p=p->next;
        }
        if(root->right!=NULL) {
            root->right->next=p;
        }
        if(root->left!=NULL) {
            if(root->right==NULL) root->left->next = p; else root->left->next=root->right;
        }
        connect(root->right);
        connect(root->left);
    }
};
