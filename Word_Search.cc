class Solution {
private:
    int row, column;
    int n;
    string wort;
    vector<vector<bool>> V;
    //vector<vector<bool>> V2;
    vector<vector<char>> bd;
public:
    bool search(int hang, int lie, int step) {
        bool ff1, ff2, ff3, ff4;
        ff1=ff2=ff3=ff4=false;
        if(step==n) {
            return true;
        }
        if(lie<column-1 && !V[hang][lie+1] && bd[hang][lie+1]==wort[step]) {
            V[hang][lie+1] = 1;
            ff1 = search(hang, lie+1, step+1);
            if(ff1) return true;
            V[hang][lie+1] = 0;
        }
        if(hang<row-1 && !V[hang+1][lie] && bd[hang+1][lie]==wort[step]) {
            V[hang+1][lie] = 1;
            ff2 = search(hang+1, lie, step+1);
            if(ff2) return true;
            V[hang+1][lie] = 0;
        }
        if(lie>0 && !V[hang][lie-1] && bd[hang][lie-1]==wort[step]) {
            V[hang][lie-1] = 1;
            ff3 = search(hang, lie-1, step+1);
            if(ff3) return true;
            V[hang][lie-1] = 0;
        }
        if(hang>0 && !V[hang-1][lie] && bd[hang-1][lie]==wort[step]) {
            V[hang-1][lie] = 1;
            ff4 = search(hang-1, lie, step+1);
            if(ff4) return true;
            V[hang-1][lie] = 0;
        }
        return 0;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        vector<bool> bl;
        bool ff;
        row = board.size();
        column = board[0].size();
        bd = board;
        V.clear();
        //V2.clear();
        bl.clear();
        for(int i=0;i<column;i++) bl.push_back(0);
        for(int i=0;i<row;i++) {
            V.push_back(bl);
            //V2.push_back(bl);
        }
        n=word.length();
        wort = word;
        if(n==0) return false;
        for(int i=0;i<row;i++) 
            for(int j=0;j<column;j++) {
                if(board[i][j]==word[0]) {
                    V[i][j]=1;
                    ff = search(i, j,1);
                    V[i][j]=0;
                    if(ff) return 1;
                }
            }
        return 0;
    }
};
