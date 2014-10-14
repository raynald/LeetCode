class Solution {
    public:
        int maxProduct(int A[], int n) {
            int max, min, amin, amax, ans;

            max = -1;
            min = 1;
            ans = A[0];
            for(int i=1;i<n;i++) {
                if(A[i]>ans) ans = A[i];
            }
            for(int i=0;i<n;i++) {
                if(A[i] == 0) {
                    max = -1;
                    min = 1;
                    continue;
                }
                if(A[i] > 0) {
                    amax = A[i];
                    amin = 1;
                    if(min < 0) amin = min * A[i];
                    if(max > 0) amax = max * A[i]; 
                    max = amax;
                    min = amin;
                }
                if(A[i] < 0) {
                    amax = -1;
                    amin = A[i];
                    if(min < 0) amax = min * A[i];
                    if(max > 0) amin = max * A[i];
                    max = amax;
                    min = amin;
                }
                if (max > 0 && max > ans) ans = max;
            }
            return ans;
        }
};
