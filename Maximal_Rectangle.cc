class Solution {
private:
    struct cmp {
        int index;
        int val;
        cmp () {}
        cmp (int x, int y) {
            index = x;
            val = y;
        }
    };
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m,n;
        m = matrix.size();
        if(m==0) return 0;
        n = matrix[0].size();
        int dp1[n], dp2[n], l[n], r[n];
        cmp tmp;
        vector<cmp> stack;
        int ans=0;
        
        for(int i=0;i<n;i++) dp2[i] = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='0') dp1[j] = 0;
                else dp1[j] = dp2[j] + 1;
            }
            stack.clear();
            for(int j=0;j<n;j++) {
                if(stack.empty()) {
                    stack.push_back(cmp(j,dp1[j]));
                    l[j]=-1;
                }
                else {
                    tmp = stack.back();
                    if(tmp.val<dp1[j]) {
                        stack.push_back(cmp(j,dp1[j]));
                        l[j] = tmp.index;
                    }
                    else {
                        stack.pop_back();
                        j--;
                    }
                }
            }
            stack.clear();
            for(int j=n-1;j>=0;j--) {
                if(stack.empty()) {
                    stack.push_back(cmp(j,dp1[j]));
                    r[j]=n;
                }
                else {
                    tmp = stack.back();
                    if(tmp.val<dp1[j]) {
                        stack.push_back(cmp(j,dp1[j]));
                        r[j] = tmp.index;
                    }
                    else {
                        stack.pop_back();
                        j++;
                    }
                }
            }
            for(int j=0;j<n;j++) {
                if((r[j]-l[j]-1)*dp1[j]>ans) ans = (r[j]-l[j]-1)*dp1[j];
            }
            memcpy(dp2,dp1,sizeof(dp1));
        }
        return ans;
    }
};
