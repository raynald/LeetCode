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
    ListNode *swapPairs(ListNode *head) {
        ListNode *left, *tmp, *old_left;
        left = head;
        if(left==NULL || left->next==NULL) return head;
        tmp = left->next;
        left->next = tmp->next;
        tmp->next = left;
        head = tmp;
        old_left = left;
        left = left->next;
        while(left != NULL && left->next !=NULL) {
            tmp = left->next;
            left->next=tmp->next;
            tmp->next=left;
            old_left->next=tmp;
            old_left = left;
            left = left -> next;
        }
        return head;
    }
};
