class Solution {
private:
    int ans;
public:
    int diff(int x, int y) {
        return x>y?x-y:y-x;
    }
    void find(vector<int> &num, int left, int right, int x) {
        int tmp;
        
        if(left>right) return;
        int mid=(left+right)/2;
        if(diff(num[mid], x)<diff(ans,x)) ans = num[mid];
        
        if(num[mid]==x) return;
        if(num[mid]<x) {
            find(num, mid+1, right, x);
        }
        else {
            find(num, left, mid-1, x);
        }
    }
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int sum, tmp;
        
        sum = 2000000000;
        sort(num.begin(), num.end());
        for(int i=0;i<n;i ++) {
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j=i+1;j<n;j++) {
                    if(j>i+1 && num[j]==num[j-1]) continue;
                    ans = 2000000000;
                    find(num, j+1, n-1, target-num[i]-num[j]);
                    tmp = ans + num[i]+num[j];
                    if(diff(tmp,target)<diff(sum,target)) sum = tmp;
            }
        }
        return sum;
    }
};
