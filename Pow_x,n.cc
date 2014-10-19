class Solution {
    public:
        double pow(double x, int n) {
            double ans;
            double sum[60];
            int p;
            int count;

            ans = x;
            count = 0;
            p=n;
            if(n==0) return 1;
            if(n<0) {ans = 1/x;p=-n;}
            sum[1]=ans;
            for(int i=2;i<60;i++) {
                sum[i]=sum[i-1]*sum[i-1];
            }
            ans = 1;
            while(p>0) {
                count ++;
                if(p%2) ans *= sum[count];
                p/=2;
            }
            return ans;
        }
};
