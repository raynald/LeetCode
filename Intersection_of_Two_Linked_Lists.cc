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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB == NULL) return NULL;
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        int cA = 0, cB = 0;
        while(nodeA->next != NULL) {
            nodeA=nodeA->next;
            cA++;
        }
        while(nodeB->next != NULL) {
            nodeB=nodeB->next;
            cB++;
        }
        if(nodeA != nodeB) return NULL;
        while(cA>cB) {
            headA = headA -> next;
            cA--;
        }
        while(cA<cB) {
            headB = headB -> next;
            cB--;
        }
        while(headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
