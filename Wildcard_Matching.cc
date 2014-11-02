class Solution {
private:
    int m;
    struct cmp {
        char val;
        int cou;
        cmp () {}
        cmp(int x, int y): val(x), cou(y) {}
    };
    struct cmp2 {
        int x;
        int y;
        cmp2() {}
        cmp2(int u, int v): x(u), y(v) {}
    };
public:
    bool isMatch(const char *s, const char *p) {
        int t, j, n;
        int start, match;
        
        for(j=0;p[j]!='\0';j++);
        for(n=0;s[n]!='\0';n++);
        int pre[j+2];
        memset(pre,0,sizeof(pre));
        for(int i=j-1;i>=0;i--) {
            pre[i]=pre[i+1];
            if(p[i]!='*') pre[i]++;
        }
        bool dp1[n+2], dp2[n+2];
        memset(dp1,0,sizeof(dp1));
        dp1[0]=1;start = 0;
        for(int t=0;t<j;t++) {
            //cout << t << " " << dp1[0] << " " << dp1[1]<<endl;
            memset(dp2,0,sizeof(dp2));
            match = start;start = n+1;
            if(match==n) {
                if(p[t]=='*') {
                    dp2[n]=1;
                    start = n;
                }
            }
            else {
                for(int i=match;i+pre[t+1]<=n;i++) {
                    if(!dp1[i]) continue;
                    if(p[t]=='*') {
                        for(int k=0;i+k<=n;k++) {
                            dp2[i+k]=1;
                            if(i+k<start) start = i+k;
                        }
                    }
                    else {
                        if(p[t]=='?' || p[t]==s[i]) {
                            dp2[i+1]=1;
                            if(i+1<start) start = i+1;
                        }
                    }
                }
            }
            memcpy(dp1,dp2,sizeof(dp2));
        }
        return dp1[n];
    }
};
