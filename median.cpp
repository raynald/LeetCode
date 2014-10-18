class Solution {
    public:
        double search(int A[], int m, int B[], int n, int place) {
            if (m>n)
                return (B, n, A, m, place);
            if (m==0)
                return B[place - 1];
            if (place == 1)
                return min(A[0], B[0]);
            x = place%2;
            if(x>m) x=m;
            y = k - x;
            if(A[x-1] < B[y-1]) {
                return search(A+x, m-x, B, n, k-x);
            }
            else if (A[x-1] > B[y-1]) {
                return search(A, M, B+y, n-y, k-y);
            }
            else
                return A[x-1];

        }
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            total = m+n;
            if(total % 2) {
                return search(A, m, B, n, total/2+1);
            }
            else {
                return (search(A, m, B, n, total/2)+search(A, m, B, n, total/2+1))/2;
            }
        }

};

