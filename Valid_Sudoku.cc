class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int x,y;
        string tmp;
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                x = i*3;
                y = j*3;
                tmp = "";
                for(int k=0;k<3;k++) 
                    for(int l=0;l<3;l++)
                        tmp = tmp + board[x+k][y+l];
                for(int k=0;k<9;k++)
                    for(int l=k+1;l<9;l++) {
                        if(tmp[k]==tmp[l] && tmp[k]!='.') return false;
                    }
            }
        }
        for(int i=0;i<9;i++) {
            tmp = "";
            for(int j=0;j<9;j++)
                tmp+=board[i][j];
            for(int k=0;k<9;k++)
                for(int l=k+1;l<9;l++) {
                    if(tmp[k]==tmp[l] && tmp[k]!='.') return false;
                }
            tmp="";
            for(int j=0;j<9;j++)
                tmp+=board[j][i];
            for(int k=0;k<9;k++)
                for(int l=k+1;l<9;l++) {
                    if(tmp[k]==tmp[l] && tmp[k]!='.') return false;
                }
        }
        return true;
    }
};
