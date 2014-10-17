class Solution {
private:
    int pai;
    int lie;
    vector<vector<int>> keep;
public:
    void search(vector<int> &S, bool v[], int from, int step) {
        vector<int> hold;
        
        if(step==lie) {
            hold.clear();
            for(int i=0;i<pai;i++)
                if(v[i]) hold.push_back(S[i]);
            keep.push_back(hold);
        }
        for(int i=from;i<pai;i++) {
            if(i>from && S[i]==S[i-1]) continue;
            v[i] = 1;
            search(S, v, i+1, step+1);
            v[i] = 0;
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        keep.clear();
        pai = S.size();
        bool v[pai];
        for(int i=0;i<=pai;i++) {
            lie = i;
            memset(v,0,sizeof(v));
            search(S, v, 0, 0);
        }
        return keep;
    }
};
