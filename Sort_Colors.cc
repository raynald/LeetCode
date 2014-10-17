class Solution {
public:
    void sortColors(int A[], int n) {
        int start = 0;
        int end = n-1;
        int tmp;
        for(int i=0;i<n;i++) {
            if(A[i]==0 && i>start) {
                tmp = A[i];
                A[i] = A[start];
                A[start]= tmp;
                start++;
                i--;
            }
            if(A[i]==2 && i<end) {
                tmp = A[i];
                A[i] = A[end];
                A[end] = tmp;
                end--;
                i--;
            }
        }
    }
};
