class Solution {
private:
    int min, max;
    
public:
    void search(int A[], int left, int right, int index) {
        if(left>right) return;
        int mid = (left+right)/2;
        if(A[mid] == index) {
            if(max<mid) max = mid;
            if(min>mid) min = mid;
            search(A, left, mid-1, index);
            search(A, mid+1, right, index);
        }
        if(A[mid] < index) search(A, mid+1, right, index);
        if(A[mid] > index) search(A, left, mid-1, index);
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        int left, right;
        vector<int> ans;
        
        ans.clear();
        min = n;
        max = 0;
        search(A, 0, n-1, target);
        if(min==n) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else {
            ans.push_back(min);
            ans.push_back(max);
        }
        return ans;
    }
};
