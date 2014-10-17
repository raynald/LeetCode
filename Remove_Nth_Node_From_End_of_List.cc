/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *p1, *p2, *p3;

            p1 = head;p2 = head;
            for(int i=0;i<n;i++) p1 = p1->next;
            if(p1==NULL) {
                p3 = head;
                head = head -> next;
            }
            else {
                while(p1->next!=NULL) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                p3 = p2->next;
                p2->next=p3->next;
            }
            return head;
        }
};
