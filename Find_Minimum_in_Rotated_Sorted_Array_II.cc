class Solution {
public:
    int binary_search(int left, int right, vector<int> &num) {
        int tmp1, tmp2, mid;
        
        if(right==left) return num[left];
        if(right-left==1) return num[left]<num[right]?num[left]:num[right];
        mid = (left+right)/2;
        if (num[left] < num[mid]) {
            tmp1 = num[left];
        }
        else {
            tmp1 = binary_search(left + 1, mid, num);
        }
        if(num[mid]<num[right]) {
            tmp2 = num[mid];
        }
        else {
            tmp2 = binary_search(mid+1, right, num);
        }
        return tmp1 < tmp2 ? tmp1:tmp2;
    }
    
    int findMin(vector<int> &num) {
        return binary_search(0, num.size()-1, num);
    }
};
