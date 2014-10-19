class Solution {
    private:
    public:
        bool canJump(int A[], int n) {
            int i=0;
            int ind=A[i]+i;
            while(ind<n-1 && i<ind) {
                i++;
                if(A[i]+i>ind) ind=A[i]+i;
            }
            if(ind>=n-1) return 1;
            return 0;
        }
};
