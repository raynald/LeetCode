class Solution {
    public:
        int min(int x, int y) {
            return x>y?y:x;
        }

        double search(int A[], int m, int B[], int n, int place) {
            int x, y;
            
            if (m>n)
                return search(B, n, A, m, place);
            if (m==0)
                return B[place - 1];
            if (place == 1)
                return min(A[0], B[0]);
            x = place / 2;
            if(x > m) x = m;
            y = place - x;
            if(A[x-1] < B[y-1]) {
                return search(A+x, m-x, B, n, place - x);
            }
            else if (A[x-1] > B[y-1]) {
                return search(A, m, B+y, n-y, place - y);
            }
            else
                return A[x-1];

        }

        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            int total; 
            
            total = m+n;
            if(total % 2) {
                return search(A, m, B, n, total/2+1);
            }
            else {
                return (search(A, m, B, n, total/2)+search(A, m, B, n, total/2+1))/2;
            }
        }
};

