class Solution {
public:
    int search(int A[], int left, int right, int index) {
        if(left>right) return left;
        int mid=(left+right)/2;
        
        if(A[mid]==index) return mid;
        if(A[mid]< index) return search(A, mid+1, right, index);
        if(A[mid]> index) return search(A, left, mid-1, index);
    }
    
    int searchInsert(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }
};
