/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
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
        TreeNode *buildTree(ListNode *list, int num) {
            if(num==0) return NULL;
            int mid=(num+1)/2;
            ListNode *tmp = list;
            for(int i=1;i<mid;i++)
                tmp = tmp -> next;
            TreeNode *node = new TreeNode(tmp->val);
            TreeNode *links = buildTree(list, mid - 1);
            TreeNode *rechts = buildTree(tmp->next, num - mid);
            node->left = links;
            node->right = rechts;
            return node;
        }

        TreeNode *sortedListToBST(ListNode *head) {
            int num = 0;
            ListNode *node = head;
            while(node!=NULL) {
                num ++;
                node = node->next;
            }
            return buildTree(head, num);
        }
};

