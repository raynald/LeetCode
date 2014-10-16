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
    bool hasCycle(ListNode *head) {
        ListNode *link1, *link2;
        int count=0;
        bool flag = 1;
        
        if(head==NULL || head->next==NULL) return 0;
        link1=link2=head;
        do {
            link1=link1->next;
            if(link1==NULL) {
                flag=0;
                break;
            }

            link2=link2->next;
            if(link2==NULL) {
                flag=0;
                break;
            }
            link2 = link2 ->next;
            if(link2==NULL) {
                flag=0;
                break;
            }
            count++;
        }
        while(link1!=link2);
        return flag;
    }
};
