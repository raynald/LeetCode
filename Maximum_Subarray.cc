class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int count;
            int ans;

            count = 0; ans = -2000000000;
            for(int i=0;i<n;i++) if(A[i]>ans) ans = A[i];
            for(int i=0;i<n;i++) {
                if(count+A[i]<0) count = 0; else {
                    count = count + A[i];
                    if(count>ans) ans = count;
                }
            }
            return ans;
        }
};
