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
    void reorderList(ListNode *head) {
        ListNode *node, *ser, *tmp, *par;
        vector<ListNode*> vec;
        int count=0;
        
        if(head==NULL) return;
        vec.clear();
        node = head;
        while(node!=NULL) {
            vec.push_back(node);
            node=node->next;
        }
        count = vec.size();
        node = head;
        for(int i=0;i<(count-1)/2;i++) {
            ser = vec.back();
            vec.pop_back();
            tmp = node -> next;
            node -> next = ser;
            ser -> next = tmp;
            node = tmp;
        }
        if(count%2==0) node = node -> next;
        node->next = NULL;
    }
};
