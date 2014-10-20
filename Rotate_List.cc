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
    ListNode *rotateRight(ListNode *head, int k) {
        int length;
        ListNode *node, *note, *tmp;

        length = 1;
        node = head;
        if(head==NULL) return NULL;
        while(node->next!=NULL) {
            length ++;
            node = node -> next;
        }
        while(k>=length) k-=length;
        if(k==0) return head;
        note = head;
        for(int i=0;i<length-k-1;i++) {
            note = note -> next;
        }
        tmp = note -> next;
        note -> next = NULL;
        node -> next = head;
        head = tmp;
        return head;
    }
};
