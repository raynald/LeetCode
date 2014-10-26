class Solution {
private:
    TreeNode *swap1, *swap2;
    int tmp;
public:
    void recoverTree(TreeNode *root) {
        TreeNode *cur = root;
        TreeNode *parent;
        
        swap1=swap2=NULL;
        parent = NULL;
        while(cur!=NULL) {
            if(cur->left != NULL) {
                TreeNode *pre = cur->left;
                while(pre->right!=NULL && pre->right!=cur) {
                    pre=pre->right;
                }
                if(pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if(parent!=NULL && cur->val<parent->val) {
                        if(swap1==NULL) swap1=parent;
                        swap2=cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
            else {
                if(parent!=NULL && cur->val<parent->val) {
                    if(swap1==NULL) swap1=parent;
                    swap2=cur;
                }
                parent = cur;
                cur = cur->right;
            }
        }
        tmp = swap1->val;
        swap1->val=swap2->val;
        swap2->val=tmp;
    }
};

