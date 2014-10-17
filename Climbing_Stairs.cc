class Solution {
public:
    int climbStairs(int n) {
        int x,y, tmp;
        if(n==0) return 0;
        if(n==1) return 1;
        x=1;
        y=1;
        for(int i=2;i<=n;i++) {
            tmp = x+y;
            x=y;
            y=tmp;
        }
        return y;
    }
};
