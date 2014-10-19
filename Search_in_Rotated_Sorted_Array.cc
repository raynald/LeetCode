class Solution {
    public:
        int binary_search(int A[], int left, int right, int x) {
            int tmp1;

            if(left>right) return -1;
            int mid = (left+right)/2;
            if(A[mid]==x) return mid;
            if(A[mid]>x) {
                tmp1 = binary_search(A, left,mid-1,x);
                if(tmp1!=-1) return tmp1;
                if(A[mid]>A[right]) return binary_search(A,mid+1, right, x);
            }
            if(A[mid]<x) {
                tmp1 = binary_search(A, mid+1, right, x);
                if(tmp1!=-1) return tmp1;
                if(A[mid]<A[left]) return binary_search(A, left,mid-1,x);
            }
            return -1;
        }
        int search(int A[], int n, int target) {
            return binary_search(A, 0, n-1, target);
        }
};
