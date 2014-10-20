/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode *x, ListNode *y) {
        ListNode *temp;
        if(x==NULL) return y;
        if(y==NULL) return x;
        if(x->val > y->val) {
            temp = merge(x, y->next);
            y->next = temp;
            return y;
        }
        else {
            temp = merge(x->next, y);
            x->next = temp;
            return x;
        }
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        return merge(l1, l2);
    }
};
