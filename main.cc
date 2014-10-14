#include<iostream>
#include"Sort_list.cc"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

int main() {
    ListNode *p1,*p2;
    p1 = p2 = ListNode(2);
    p2->next = ListNode(1);
    Solution sol;
    p1 = sol.sortList(p1);
    while(p1!=NULL) {
        cout << p1->val << endl;
        p1 = p1 ->next;
    }
    return 0;
}
