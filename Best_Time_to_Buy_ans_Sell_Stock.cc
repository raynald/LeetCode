class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n;
        int minp;
        int ans = 0;
        n = prices.size();
        if(n==0) return ans;
        minp=prices[0];
        for(int i=1;i<n;i++) {
            if(prices[i]-minp>ans) ans = prices[i]-minp;
            if(prices[i]<minp) minp = prices[i];
        }
        return ans;
    }
};
