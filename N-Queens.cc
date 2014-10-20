class Solution {
private:
    int num;
    vector<bool> v;
    vector<int> a;
    vector<vector<string> > ans;
    string sum;

public:
    void search(int x) {
        vector<string> temp;
        string stemp;
        bool conf;
        
        if(x==num) {
            temp.clear();
            for(int i=0;i<x;i++) {
                stemp=sum;
                stemp[a[i]]='Q';
                temp.push_back(stemp);
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<num;i++) {
            if(v[i]) continue;
            conf = 0;
            for(int j=0;j<x;j++) {
                if(x-j==i-a[j] || x-j == a[j]-i) {
                    conf = 1;
                    break;
                }
            }
            if(conf) continue;
            v[i] = 1;
            a[x] = i;
            search(x+1);
            a[x] = 0;
            v[i] = 0;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        num = n;
        v.clear();
        sum = "";
        ans.clear();
        for(int i=0;i<num;i++) {
            sum += ".";
            v.push_back(0);
            a.push_back(0);
        }
        if(n>0) search(0);
        return ans;
    }
};
