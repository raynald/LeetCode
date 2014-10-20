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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *node, *next, *temp;
        
        if(head==NULL || head->next == NULL) return head;
        node = head;next = node->next;
        if(node->val!=next->val) {
            temp = deleteDuplicates(next);
            head ->next = temp;
            return head;
        }
        else {
            while(next!=NULL && node->val==next->val) {
                node = next;
                next = next->next;  
            }
            return deleteDuplicates(next);
        }
    }
};

