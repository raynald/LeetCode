/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     ListNode *next;
 *
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *
 *       * };
 *
 *        */

class Solution {

    public:

            ListNode *mergesort(ListNode *start, int n) {

                        if(n==1) return start;

                                int mid = n/2;

                                        ListNode *right = start;

                                                ListNode *p1, *p2, *np, *np2;

                                                        for(int i=1;i<=mid;i++) {

                                                                        right = right->next;

                                                                                }

                                                                mergesort(start, mid);

                                                                        mergesort(right, n-mid);

                                                                                if(start->val<right->val) {

                                                                                                np = start;

                                                                                                            p1 = start->next;

                                                                                                                    }

                                                                                        else {

                                                                                                        np = right;

                                                                                                                    p2 = right->next;

                                                                                                                            }

                                                                                                np2 = np;

                                                                                                        while(p1!=NULL && p2!=NULL) {

                                                                                                                        if (p1->val<p2->val) {

                                                                                                                                            np -> next = p1;

                                                                                                                                                            np = p1;

                                                                                                                                                                            p1 = p1 -> next;

                                                                                                                                                                                        }

                                                                                                                                    else {

                                                                                                                                                        np -> next = p2;

                                                                                                                                                                        np = p2;

                                                                                                                                                                                        p2 = p2 -> next;

                                                                                                                                                                                                    }

                                                                                                                                            }

                                                                                                                while(p1!=NULL) {

                                                                                                                                np -> next = p1;

                                                                                                                                            np = p1;

                                                                                                                                                        p1 = p1 -> next;

                                                                                                                                                                }

                                                                                                                        while(p2!=NULL) {

                                                                                                                                        np -> next = p2;

                                                                                                                                                    np = p2;

                                                                                                                                                                p2 = p2 -> next;

                                                                                                                                                                        }

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
