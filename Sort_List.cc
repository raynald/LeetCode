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
        ListNode *mergesort(ListNode *start, int n) {
            cout << start-> val << " " << n<< endl;
            if(n==1) return start;
            int mid = n/2;
            ListNode *right = start;
            ListNode *p1, *p2, *np, *np2;
            int l1=mid;
            int l2=n-mid;
            for(int i=1;i<=mid;i++) {
                right = right->next;
            }
            start = mergesort(start, mid);
            right = mergesort(right, n-mid);
            if(start->val<right->val) {
                np = start;
                p1 = start->next;
                p2 = right;
                l1--;
            }
            else {
                np = right;
                p2 = right->next;
                p1 = start;
                l2--;
            }
            np2 = np;
            while(l1!=0 && l2!=0) {
                cout <<"loop1"<<endl;
                if (p1->val<p2->val) {
                    np -> next = p1;
                    np = p1;
                    p1 = p1 -> next;
                    l1--;
                }
                else {
                    np -> next = p2;
                    np = p2;
                    p2 = p2 -> next;
                    l2--;
                }
            }
            while(l1!=0) {
                cout << p1->val << endl;
                if(p1==p1->next) cout <<"fuck"<<endl;
                cout <<"loop2"<<endl;
                np -> next = p1;
                np = p1;
                p1 = p1 -> next;
                l1--;
            }
            while(l2!=0) {
                cout <<"loop3"<<endl;
                np -> next = p2;
                np = p2;
                p2 = p2 -> next;
                l2--;
            }
            np->next=NULL;
            return np2;
        }

        ListNode *sortList(ListNode *head) {
            if(head==NULL) return NULL;
            int length = 0;
            ListNode *p = head;
            while(p!=NULL) {
                length ++;
                p = p -> next;
            }
            return mergesort(head, length);
        }
};
