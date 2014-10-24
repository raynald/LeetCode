class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n;
        int minp, maxp;
        int ans=0;
        n = prices.size();
        if(n==0) return ans;
        int left[n+2];
        int right[n+2];
        left[0]=left[1] = right[n+1]=right[n]=0;
        minp=prices[0];
        for(int i=1;i<n;i++) {
            if(prices[i]-minp>ans) ans = prices[i]-minp;
            if(prices[i]<minp) minp = prices[i];
            left[i+1] = ans;
        }
        ans = 0;
        maxp=prices[n-1];
        for(int i = n-2;i>=0;i--) {
            if(maxp - prices[i]>ans) ans = maxp - prices[i];
            if(prices[i]>maxp) maxp = prices[i];
            right[i+1] = ans;
        }
        ans = 0;
        for(int i=0;i<=n;i++) {
            if(left[i]+right[i+1]>ans) ans = left[i]+right[i+1];
        }
        return ans;
    }
};
