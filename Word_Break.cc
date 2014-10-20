class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string>::const_iterator got;
        bool dp[s.length()+1];

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=s.length();i++) {
            got = dict.find(s.substr(0,i));
            if(got!=dict.end()) {
                dp[i-1]=1;
            }
        }
        for(int i=1;i<s.length();i++) {
            if(!dp[i-1]) continue;
            for(int j=1;j<=s.length()-i;j++) {
                if(dp[i+j-1]) continue;
                got = dict.find(s.substr(i,j));
                if(got!=dict.end()) {
                    dp[i+j-1]=1;
                }
            }
        }
        return dp[s.length()-1];
    }
};
