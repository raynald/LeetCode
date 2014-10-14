#include<iostream>
#include"Sort_list.cc"

int main() {
    ListNode p2(3);
    ListNode *p1= &p2;
    ListNode *head=p1;
    ListNode p3(4);
    p2.next = &p3;
    ListNode p4(1);
    p3.next = &p4;
    Solution sol;
    p1 = head;
    while(p1!=NULL) {
        cout << p1->val << endl;
        p1 = p1 ->next;
    }
    p1 = head;
    p1 = sol.sortList(p1);
    while(p1!=NULL) {
        cout << p1->val << endl;
        p1 = p1 ->next;
    }
    return 0;
}
