class Solution {
public:
    bool check(string s) {
        int n = s.length();
        for(int i=0;i<n/2;i++) if (s[i]!=s[n-1-i]) return 0;
        return 1;
    }

    vector<vector<string>> partition(string s) {
        string tmp;
        vector<vector<string> > store;
        vector<string> temp;
        bool got;
        int n = s.length();
        bool T[n][n];
        vector<vector<string> > dp[n+1];
        
        store.clear();
        memset(T,0,sizeof(T));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-i;j++){
                tmp = s.substr(i,j+1);
                got = check(tmp);
                if(got) {
                    T[i][i+j]=1;
                }
            }
        }
        dp[0].clear();
        for(int i=0;i<n;i++) {
            dp[i+1].clear();
            for(int j=0;j<=i;j++) {
                if(T[j][i]) {
                    if(j==0) {
                        store = dp[0];
                        temp.clear();
                        temp.push_back(s.substr(0,i+1));
                        store.push_back(temp);
                    }
                    else {
                        store = dp[j];
                        for(int k=0;k<store.size();k++) {
                            store[k].push_back(s.substr(j,i-j+1));
                        }
                    }
                    for(int k=0;k<store.size();k++) {
                        dp[i+1].push_back(store[k]);
                    }
                }
            }
        }
        return dp[n];
    }
};

