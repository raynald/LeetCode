class Solution {
private:
    bool flag;
    int a[82];
    bool block[10][10];
    bool row[10][10];
    bool column[10][10];

public:
    void search(int step) {
        if(step==81) {
            flag = 1;
            return;
        }
        int x = step/9;
        int y = step%9;
        if(a[step] == -1) {
            search(step+1);
            if(flag) return;
        }
        else {
            for(int i=1;i<=9;i++) {
                if(!row[x][i] && !column[y][i] && !block[x/3*3+y/3][i]) {
                    row[x][i]=1;
                    column[y][i]=1;
                    block[x/3*3+y/3][i]=1;
                    a[step]=i;
                    search(step+1);
                    if(flag) return;
                    a[step]=0;
                    row[x][i]=0;
                    column[y][i]=0;
                    block[x/3*3+y/3][i]=0;
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                row[i][j]=0;column[i][j]=0;block[i][j]=0;
            }
        }
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    row[i][board[i][j]-'0']=1;
                    column[j][board[i][j]-'0']=1;
                    block[i/3*3+j/3][board[i][j]-'0']=1;
                    a[i*9+j] = -1;
                }
                else a[i*9+j] = 0;
            }
        }
        flag = 0;
        search(0);
        if(flag) {
            for(int i=0;i<9;i++) {
                for(int j=0;j<9;j++) {
                    if(board[i][j]=='.') {
                        board[i][j]=char('0'+a[i*9+j]);
                    }
                }
            }
        }
    }
};
