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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dank, *alt_dank, *temp, *arc, *node, *tail;
        int count, T;
        
        node = head; T = m-1;
        while(node!=NULL && --T>0) {
            node = node -> next;
        }
        if(m!=1) {
            tail = node;
            node = node -> next;
        }
        alt_dank = dank = node;
        count = 1;
        while(dank->next!=NULL && count <= n-m) {
            arc = dank -> next;
            temp = arc->next;
            arc->next = alt_dank;
            alt_dank = arc;
            dank -> next = temp;
            count ++;
        }
        if(m==1) return alt_dank; else {
            tail -> next = alt_dank;
            return head;
        }
    }
};
