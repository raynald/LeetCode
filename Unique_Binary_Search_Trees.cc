class Solution {
public:
    int numTrees(int n) {
        double ans=1.0;
        
        for(int i=0;i<n;i++) {
            ans= ans * (2*n-i) / (i+1);
        }
        ans /= (n+1);
        return int(ans);
    }
};
