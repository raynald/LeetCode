class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            int n = triangle.size();
            int dp1[n+1], dp2[n+1];
            memset(dp1,0,sizeof(dp1));
            for(int i=0;i<n;i++) {
                dp2[0] = dp1[0] + triangle[i][0];            
                for(int j=1;j<i;j ++) {
                    dp2[j] = min(dp1[j-1],dp1[j])+triangle[i][j];
                }
                if(i>0) dp2[i] = dp1[i-1] + triangle[i][i];
                memcpy(dp1,dp2,sizeof(dp2));
            }
            int ans=dp1[0];
            for(int i=1;i<n;i++)
                if(dp1[i]<ans) ans=dp1[i];
            return ans;
        }
};
