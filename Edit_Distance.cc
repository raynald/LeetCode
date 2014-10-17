class Solution {
public:
    int min(int x, int y) {
        return x<y?x:y;
    }
    
    int minDistance(string word1, string word2) {
        int n,m;
        int diff;
        n=word1.length();
        m=word2.length();
        int dp[n+1][m+1];
                
        for(int i=0;i<=m;i++)
            dp[0][i]=i;
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(word1[i]==word2[j]) diff=0; else diff=1;
                dp[i+1][j+1] = min(min(dp[i][j]+diff, dp[i+1][j]+1),dp[i][j+1]+1);
            }
        }
        return dp[n][m];
    }
};
