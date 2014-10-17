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
    ListNode *partition(ListNode *head, int x) {
        ListNode *small, *big, *node, *tou, *tou2;
        
        small=big=NULL;
        node = head;
        tou=tou2=NULL;
        while(node != NULL) {
            if(node->val<x) {
                if(small==NULL) {
                    small = tou = node;
                }
                else {
                    small->next = node;
                    small = small -> next;
                }
            }
            else {
                if(big == NULL) {
                    big=tou2 = node;
                }
                else {
                    big->next=node;
                    big=big->next;
                }
            }
            node = node->next;
        }
        if(small==NULL) {
            return tou2;
        }
        else {
            small->next=tou2;
            if(big!=NULL) big->next=NULL; 
            return tou;
        }
    }
};
