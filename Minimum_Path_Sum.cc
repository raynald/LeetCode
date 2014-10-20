class Solution {
public:
    int min(int x, int y) {
        return x>y?y:x;
    }
    int minPathSum(vector<vector<int> > &grid) {
        int m,n;
        m = grid.size();
        n = grid[0].size();
        int dp[m][n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                dp[i][j]=grid[i][j];
                if(i==0&&j==0) continue;
                if(i==0) dp[i][j]+=dp[i][j-1];
                else if(j==0) dp[i][j]+=dp[i-1][j];
                else dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
            }
        return dp[m-1][n-1];        
    }
};

