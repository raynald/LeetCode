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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *p, *par, *min_node, *min_par, *start, *new_head, *begin;
        bool flag=0;
        
        if(head==NULL) return head;
        
        start = head;
        while(start != NULL) {
            min_par = NULL;
            min_node = start;
            par = start;
            p = start->next;
            while(p!=NULL) {
                if(p->val<min_node->val) {            
                    min_node = p;
                    min_par = par;
                }
                par = p;
                p = p -> next;
            }
            if(min_par != NULL) {
                min_par->next = min_node->next;
            }
            else {
                start = start -> next;
            }
            if(!flag) {
                begin = min_node;
                flag = 1;
                new_head = begin;
            }
            else {
                begin -> next = min_node;
                begin = begin -> next;
            }
        }
        begin -> next = NULL;
        return new_head;
    }
};
