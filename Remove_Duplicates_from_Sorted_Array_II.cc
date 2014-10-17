class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ans;
        int count;
        if(n==0) return 0;
        int memory=A[0]; ans = 1;count = 1;
        for(int i=1;i<n;i++) {
            if(A[i]==memory && count == 1) {
                A[ans]=A[i];
                ans++;
                count ++;
            }
            if(A[i] != memory) {
                memory = A[i];
                A[ans]=A[i];
                count = 1;
                ans++;
            }
        }
        return ans;
    }
};
