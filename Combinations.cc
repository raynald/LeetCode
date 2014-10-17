class Solution {
private:
    int pai;
    int lie;
    vector<vector<int>> keep;
public:
    void search(bool v[], int from, int step) {
        vector<int> hold;
        
        if(step==lie) {
            hold.clear();
            for(int i=0;i<pai;i++)
                if(v[i]) hold.push_back(i+1);
            keep.push_back(hold);
        }
        for(int i=from;i<pai;i++) {
            v[i] = 1;
            search(v, i+1, step+1);
            v[i] = 0;
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        bool v[n];
        
        keep.clear();
        pai = n;
        lie = k;
        memset(v,0,sizeof(v));
        search(v, 0, 0);
        return keep;
    }
};
