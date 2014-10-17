class Solution {
public:

    int numDecodings(string s) {
        int ans;
        int n;
        
        ans = 0;
        n=s.length();
        int dp[n];
        
        if(s[0]=='0' || n==0) return 0;
        if(n==1) return 1;
        dp[0] = 1;
        if((s[0]-'0')*10+s[1]-'0'<=26) dp[1]=1; else dp[1]=0;
        if(s[1]!='0') dp[1]++;
        for(int i=2;i<n;i++) {
            dp[i]=0;
            if(s[i]!='0') dp[i]=dp[i-1];
            if(s[i-1]!='0' && (s[i-1]-'0')*10+s[i]-'0'<=26) dp[i]+=dp[i-2];
        }
        return dp[n-1];
    }
};
