class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int> ans;
            int m,n,x,y,now;
            int step[4][2];
            int tmpx,tmpy;

            ans.clear();
            m=matrix.size();
            if(m==0)return ans;
            n=matrix[0].size();
            bool v[m+2][n+2];
            memset(v,0,sizeof(v));
            for(int i=0;i<=m;i++) {v[i][0]=1;v[i][n+1]=1;}
            for(int i=0;i<=n;i++) {v[0][i]=1;v[m+1][i]=1;}
            x=0;y=0;
            step[0][0]=0;step[0][1]=1;
            step[1][0]=1;step[1][1]=0;
            step[2][0]=0;step[2][1]=-1;
            step[3][0]=-1;step[3][1]=0;
            v[1][1]=1;ans.push_back(matrix[0][0]);now=0;
            while(ans.size()!=m*n) {
                while(1) {
                    tmpx = x+step[now][0];
                    tmpy = y+step[now][1];
                    if(!v[tmpx+1][tmpy+1]) break;
                    now=(now+1)%4;
                }
                v[tmpx+1][tmpy+1]=1;
                x=tmpx;y=tmpy;
                ans.push_back(matrix[x][y]);
            }
            return ans;
        }
};
