#include"head.h"

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
        int j, n, i;
        
        for(j=0;p[j]!='\0';j++);
        for(n=0;s[n]!='\0';n++);
        cmp chi[j];
        m = 0;
        for(int i=0;p[i]!='\0';i++) {
            if(i>0 && p[i]=='*' && p[i-1]=='*') continue;
            if(p[i]=='*') {
                chi[m].val='.';
                chi[m].cou=-1;
                m++;
            }
            else if(p[i+1]=='*') {
                chi[m].val=p[i];
                chi[m].cou=-1;
                m++;
                i++;
            }
            else {
                chi[m].val=p[i];
                chi[m].cou=1;
                m++;
            }
        }


        bool dp1[n+2], dp2[n+2];
        memset(dp1,0,sizeof(dp1));
        dp1[0]=1;
        for(int j=0;j<m;j++) {
            memset(dp2,0,sizeof(dp2));
            for(int i=0;i<=n;i++) {
                if(!dp1[i]) continue;
                if(chi[j].cou==-1) {
                    dp2[i]=1;
                    for(int k=0;i+k<n;k++) {
                        if(chi[j].val=='.' || s[i+k]==chi[j].val) {
                            dp2[i+k+1]=1;
                        }
                        else break;
                    }
                }
                else if(chi[j].val=='.' || s[i]==chi[j].val) dp2[i+1]=1;
            }
            memcpy(dp1,dp2,sizeof(dp2));
        }
        return dp1[n];
    }
};

int main() {
    Solution sol;
    cout << (sol.isMatch("aa","a") == false) << endl;
    cout << (sol.isMatch("aa","aa") == true) << endl;
    cout << (sol.isMatch("aaa","aa") == false) << endl;
    cout << (sol.isMatch("aa", "a*") == true) << endl;
    cout << (sol.isMatch("aa", ".*") == true) << endl;
    cout << (sol.isMatch("ab", ".*") == true) << endl;
    cout << (sol.isMatch("aab", "c*a*b") == true) << endl;
    cout << (sol.isMatch("a", "ab*") == true) << endl;
    cout << (sol.isMatch("ab", ".*c") == false) << endl;
    return 0;
}
