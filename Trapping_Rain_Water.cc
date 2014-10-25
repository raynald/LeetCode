class Solution {
    public:
        int trap(int A[], int n) {
            int ans=0;
            int flag;
            int max = 0;
            for(int i=0;i<n;i++) {
                flag = -1;
                for(int j=i-1;j>=max;j--) {
                    if(A[i]<=A[j]) {
                        flag = j;
                        break;
                    }
                }    
                if(flag == -1) {
                    for(int j=max+1;j<=i-1;j++) {
                        ans+=A[max]-A[j];
                        A[j]=A[max];
                    }
                }
                else {
                    for(int j=flag+1;j<i;j++) {
                        ans+=A[i]-A[j];
                        A[j]=A[i];
                    }
                }
                if(A[i]>A[max]) max = i;
            }
            return ans;
        }
};
