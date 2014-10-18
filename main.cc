#include<iostream>
#include"Convert_Sorted_Array_to_Binary_Search_Tree.cc"

void print(TreeNode *p) {
    if(p==NULL) {cout << endl;return;}
    cout << p->val << endl;
    print(p->left);
    print(p->right);
}

int main() {
    Solution sol;
    vector<int> x;
    x.clear();
    x.push_back(1);
    x.push_back(3);
    TreeNode *p = sol.sortedArrayToBST(x);
    print(p);
    return 0;
}
