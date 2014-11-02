class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if(n==0) return 0;
        bool T[n][n];
        int dp[n+1];
        
        memset(T,0,sizeof(T));
        dp[0]=-1;
        for(int i=0;i<n;i++) {
            dp[i+1]=dp[i]+1;
            for(int j=0;j<=i;j++) {
                if(s[i]==s[j] && (i-j<2 || T[j+1][i-1])) {
                    T[j][i]=1;
                    if(dp[j]+1<dp[i+1]) dp[i+1]=dp[j]+1;
                }
            }
        }
        return dp[n];
    }
};

