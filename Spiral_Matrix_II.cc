class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans;
        vector<int> sum;
        
        int x,y, now;
        int step[4][2];
        int tmpx,tmpy;
        int count;
        
        ans.clear();
        sum.clear();
        if(n==0)return ans;
        bool v[n+2][n+2];
        memset(v,0,sizeof(v));
        for(int i=0;i<=n;i++) {v[i][0]=1;v[i][n+1]=1;if(i) sum.push_back(0);}
        for(int i=0;i<=n;i++) {v[0][i]=1;v[n+1][i]=1;if(i) ans.push_back(sum);}
        x=0;y=0;
        step[0][0]=0;step[0][1]=1;
        step[1][0]=1;step[1][1]=0;
        step[2][0]=0;step[2][1]=-1;
        step[3][0]=-1;step[3][1]=0;
        count = 2;
        v[1][1]=1;ans[0][0]=1;now=0;
        while(count<=n*n) {
            while(1) {
                tmpx = x+step[now][0];
                tmpy = y+step[now][1];
                if(!v[tmpx+1][tmpy+1]) break;
                now=(now+1)%4;
            }
            v[tmpx+1][tmpy+1]=1;
            x=tmpx;y=tmpy;
            ans[tmpx][tmpy]=count;
            count++;
        }
        return ans;      
    }
};
