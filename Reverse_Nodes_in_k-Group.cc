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
        ListNode* reverse(ListNode *node, int k) {
            ListNode *dank, *alt_dank, *temp, *arc;
            int count;

            if(node==NULL) return NULL;
            alt_dank = dank = node;
            count = 1;
            while(dank->next!=NULL && count < k) {
                arc = dank -> next;
                temp = arc->next;
                arc->next = alt_dank;
                alt_dank = arc;
                dank -> next = temp;
                count ++;
            }
            return alt_dank;
        }
        ListNode *reverseKGroup(ListNode *head, int k) {
            ListNode *new_head;
            ListNode *node, *temp, *old_node;
            int n=0;

            if(head==NULL) return NULL;
            node = head;
            while(node!=NULL) {
                n++;
                node=node->next;
            }
            if(n>=k) {
                n-=k;
                new_head = reverse(head, k);
                old_node = head;
                node = head -> next;
                while(n>=k && node!=NULL) {
                    n-=k;
                    temp = reverse(node, k);
                    old_node->next = temp;
                    old_node = node;
                    node = node -> next;
                }
            }
            else {
                new_head = head;
            }
            return new_head;
        }
};
