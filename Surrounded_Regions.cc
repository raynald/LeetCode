class Solution {
private:
    struct point {
        int x;
        int y;
        point() {}
        point(int u, int v) {
            x = u;
            y = v;
        }
    };
public:
    void solve(vector<vector<char>> &board) {
        int n,m;
        n = board.size();
        if(n==0) return;
        m = board[0].size();
        bool v[n][m];
        vector<point> vec;
        point p;
        
        memset(v,0,sizeof(v));
        for(int i = 0;i < m;i ++) {
            if(board[0][i] == 'O' && !v[0][i]) {
                v[0][i] = 1;
                vec.clear();
                vec.push_back(point(0,i));       
                while(vec.size()!=0) {
                    p = vec.back();
                    vec.pop_back();
                    if(p.y<m-1 && board[p.x][p.y+1] == 'O' && !v[p.x][p.y+1]) {
                        v[p.x][p.y+1] = 1;
                        vec.push_back(point(p.x,p.y+1));
                    }
                    if(p.x<n-1 && board[p.x+1][p.y] == 'O' && !v[p.x+1][p.y]) {
                        v[p.x+1][p.y] = 1;
                        vec.push_back(point(p.x+1,p.y));
                    }
                    if(p.y>0 && board[p.x][p.y-1] == 'O' && !v[p.x][p.y-1]) {
                        v[p.x][p.y-1] = 1;
                        vec.push_back(point(p.x,p.y-1));
                    }
                    if(p.x>0 && board[p.x-1][p.y] == 'O' && !v[p.x-1][p.y]) {
                        v[p.x-1][p.y] = 1;
                        vec.push_back(point(p.x-1,p.y));
                    }
                }
            }
            if(board[n-1][i] == 'O' && !v[n-1][i]) {
                v[n-1][i] = 1;
                vec.clear();
                vec.push_back(point(n-1,i));       
                while(vec.size()!=0) {
                    p = vec.back();
                    vec.pop_back();
                    if(p.y<m-1 && board[p.x][p.y+1] == 'O' && !v[p.x][p.y+1]) {
                        v[p.x][p.y+1] = 1;
                        vec.push_back(point(p.x,p.y+1));
                    }
                    if(p.x<n-1 && board[p.x+1][p.y] == 'O' && !v[p.x+1][p.y]) {
                        v[p.x+1][p.y] = 1;
                        vec.push_back(point(p.x+1,p.y));
                    }
                    if(p.y>0 && board[p.x][p.y-1] == 'O' && !v[p.x][p.y-1]) {
                        v[p.x][p.y-1] = 1;
                        vec.push_back(point(p.x,p.y-1));
                    }
                    if(p.x>0 && board[p.x-1][p.y] == 'O' && !v[p.x-1][p.y]) {
                        v[p.x-1][p.y] = 1;
                        vec.push_back(point(p.x-1,p.y));
                    }
                }
            }
        }
        for(int i = 0;i < n;i ++) {
            if(board[i][0] == 'O' && !v[i][0]) {
                v[i][0] = 1;
                vec.clear();
                vec.push_back(point(i,0));       
                while(vec.size()!=0) {
                    p = vec.back();
                    vec.pop_back();
                    if(p.y<m-1 && board[p.x][p.y+1] == 'O' && !v[p.x][p.y+1]) {
                        v[p.x][p.y+1] = 1;
                        vec.push_back(point(p.x,p.y+1));
                    }
                    if(p.x<n-1 && board[p.x+1][p.y] == 'O' && !v[p.x+1][p.y]) {
                        v[p.x+1][p.y] = 1;
                        vec.push_back(point(p.x+1,p.y));
                    }
                    if(p.y>0 && board[p.x][p.y-1] == 'O' && !v[p.x][p.y-1]) {
                        v[p.x][p.y-1] = 1;
                        vec.push_back(point(p.x,p.y-1));
                    }
                    if(p.x>0 && board[p.x-1][p.y] == 'O' && !v[p.x-1][p.y]) {
                        v[p.x-1][p.y] = 1;
                        vec.push_back(point(p.x-1,p.y));
                    }
                }
            }
            if(board[i][m-1] == 'O' && !v[i][m-1]) {
                v[i][m-1] = 1;
                vec.clear();
                vec.push_back(point(i,m-1));       
                while(vec.size()!=0) {
                    p = vec.back();
                    vec.pop_back();
                    if(p.y<m-1 && board[p.x][p.y+1] == 'O' && !v[p.x][p.y+1]) {
                        v[p.x][p.y+1] = 1;
                        vec.push_back(point(p.x,p.y+1));
                    }
                    if(p.x<n-1 && board[p.x+1][p.y] == 'O' && !v[p.x+1][p.y]) {
                        v[p.x+1][p.y] = 1;
                        vec.push_back(point(p.x+1,p.y));
                    }
                    if(p.y>0 && board[p.x][p.y-1] == 'O' && !v[p.x][p.y-1]) {
                        v[p.x][p.y-1] = 1;
                        vec.push_back(point(p.x,p.y-1));
                    }
                    if(p.x>0 && board[p.x-1][p.y] == 'O' && !v[p.x-1][p.y]) {
                        v[p.x-1][p.y] = 1;
                        vec.push_back(point(p.x-1,p.y));
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O' && !v[i][j]) {
                    board[i][j]='X';
                }
            }
    }
};
