struct cmp {
    int value;
    int index;
    cmp() {}
    cmp(int u, int v): value(u), index(v) {}
};

bool operator< (const cmp &x, const cmp &y) {
    return x.value>y.value;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<cmp> q;
        cmp heute;
        ListNode *head = NULL;
        ListNode *current = NULL;
        
        if(!q.empty()) q.pop();
        for(int i=0;i<lists.size();i ++) {
            if(lists[i]!=NULL) {
                q.push(cmp(lists[i]->val, i));
                lists[i]=lists[i]->next;
            }
        }
        while(!q.empty()) {
            heute = q.top();
            q.pop();
            if(current == NULL) {
                current = new ListNode(heute.value);
                head = current;
            }
            else {
                current -> next = new ListNode(heute.value);
                current = current -> next;
            }
            if(lists[heute.index]!=NULL) {
                q.push(cmp(lists[heute.index]->val,heute.index));
                lists[heute.index]=lists[heute.index]->next;
            }
        }
        return head;
    }
};
