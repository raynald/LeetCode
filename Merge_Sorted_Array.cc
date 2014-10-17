class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int C[m+n];
        int i,j;
        int pos;
        
        i=j=0;
        pos = 0;
        while(i<m && j<n) {
            if(A[i]<B[j]) {
                C[pos]=A[i];
                pos++;
                i++;
            }
            else {
                C[pos]=B[j];
                pos++;
                j++;
            }
        }
        while(i<m) {
            C[pos]=A[i];
            i++;
            pos++;
        }
        while(j<n) {
            C[pos]=B[j];
            j++;
            pos++;
        }
        for(int i=0;i<m+n;i++) {
            A[i]=C[i];
        }
    }
};
