class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            int n = matrix.size();
            int tmp[n];
            int k,now;

            k=0;
            now = n-1;
            while(now>0) {
                for(int i=0;i<now;i++) {
                    tmp[i]=matrix[k][k+i];
                }
                for(int i=0;i<now;i++) {
                    matrix[k][k+i]=matrix[n-1-k-i][k];
                }
                for(int i=0;i<now;i++) {
                    matrix[n-1-k-i][k]=matrix[n-1-k][n-1-k-i];
                }
                for(int i=0;i<now;i++) {
                    matrix[n-1-k][n-1-k-i]=matrix[k+i][n-1-k];
                }
                for(int i=0;i<now;i++) {
                    matrix[k+i][n-1-k]=tmp[i];
                }
                now=now-2;k++;
            }
        }
};
