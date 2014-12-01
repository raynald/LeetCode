class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int w, n, i, m;
        
        w = strlen(p);
        n = strlen(s);
        m = 0;

        bool dp1[n+2], dp2[n+2];
        memset(dp1,0,sizeof(dp1));
        dp1[0]=1;
        for(int j=0;j<w;j++) {
            if(p[j]=='*') continue;
            memset(dp2,0,sizeof(dp2));
            for(int i=0;i<=n;i++) {
                if(!dp1[i]) continue;
                if(p[j+1]=='*') {
                    dp2[i]=1;
                    for(int k=0;i+k<n;k++) {
                        if(p[j]=='.' || s[i+k]==p[j]) {
                            dp2[i+k+1]=1;
                        }
                        else break;
                    }
                }
                else if(p[j]=='.' || s[i]==p[j]) dp2[i+1]=1;
            }
            memcpy(dp1,dp2,sizeof(dp2));
        }
        return dp1[n];
    }
};

