class Solution {
private:
    struct cmp {
        int val;
        int ind;
        cmp() {}
        cmp(int x, int y):val(x), ind(y) {}
    };
public:
    int largestRectangleArea(vector<int> &height) {
        int n;
        n=height.size();
        int left[n];
        int right[n];
        vector<cmp> stack;
        cmp peek;
        int ans;
        
        stack.clear();
        for(int i=0;i<n;i++) right[i]=n;
        for(int i=0;i<n;i++) {
            if(stack.empty() || height[i]>=stack.back().val) {
                stack.push_back(cmp(height[i],i));
            }
            else {
                peek = stack.back();
                right[peek.ind] = i;
                stack.pop_back();
                i--;
            }
        }
        stack.clear();
        for(int i=0;i<n;i++) left[i]=-1;
        for(int i=n-1;i>=0;i--) {
            if(stack.empty() || height[i]>=stack.back().val) {
                stack.push_back(cmp(height[i],i));
            }
            else {
                peek = stack.back();
                left[peek.ind] = i;
                stack.pop_back();
                i++;
            }
        }
        ans = 0;
        for(int i=0;i<n;i++) {
            if((right[i]-left[i]-1)*height[i]>ans) ans = (right[i]-left[i]-1)*height[i];
        }
        return ans;
    }
};

