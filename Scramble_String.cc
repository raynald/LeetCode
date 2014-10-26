class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n;
        if(s1.length()!=s2.length()) return false;
        n = s1.length();
        int dp[n][n][n+1];
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s1[i]==s2[j]) dp[i][j][1]=1;
        for(int k=2;k<=n;k++) {
            for(int i=0;i+k<=n;i++) {
                for(int j=0;j+k<=n;j++) {
                    for(int p=1;p<k;p++) {
                        if ((dp[i][j][p] && dp[i+p][j+p][k-p])
                        ||(dp[i][j+k-p][p] && dp[i+p][j][k-p])) {
                            dp[i][j][k]=1;
                            break;
                        }
                    }       
                }
            }
        }
        return dp[0][0][n];
    }
};
