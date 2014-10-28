class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n,m;
        n = s1.length();
        m = s2.length();
        bool dp[n+1][m+1];
        
        memset(dp,0,sizeof(dp));
        if(n+m!=s3.length()) return 0;
        if(s1+s2==s3 || s2+s1==s3) return 1;
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++) {
                if(!dp[i][j]) continue;
                if(i<n && s1[i]==s3[i+j]) dp[i+1][j]=1;
                if(j<m && s2[j]==s3[i+j]) dp[i][j+1]=1;
            }
        return dp[n][m];
    }
};
