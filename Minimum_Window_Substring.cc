class Solution {
private:
        int cur['z'-'0'+1];
        int a['z'-'0'+1];
public:
    bool check() {
        for(int k=0;k<='z'-'0';k++)
            if(a[k]>cur[k]){
                return 0;
            }
        return 1;
    }

    string minWindow(string S, string T) {
        int n, m, i, j;
        int ans;
        string ret="";
        n = S.length();
        m = T.length();
        ans = n+1;
        memset(a,0,sizeof(a));
        memset(cur,0,sizeof(cur));
        for(int i=0;i<m;i++) {
            a[T[i]-'0']++;
        }
        i = j = 0;
        while(j<n) {
            if(a[S[j]-'0']!=0) {
                cur[S[j]-'0']++;
                if(check()) {
                    while(a[S[i]-'0']==0 || cur[S[i]-'0']>a[S[i]-'0']) {
                        if(a[S[i]-'0']>0) cur[S[i]-'0']--;
                        i++;
                    }
                    if(j-i+1<ans) {
                        ans=j-i+1;
                        ret=S.substr(i,ans);
                    }
                }
            }
            j++;
        }
        return ret;
    }
};
