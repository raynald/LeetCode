class Solution {
private:
    int num;
    vector<bool> v;
    vector<int> a;
    int ans;
public:
    void search(int x) {
        bool conf;
        
        if(x==num) {
            ans ++ ;
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
    int totalNQueens(int n) {
        num = n;
        v.clear();
        ans = 0;
        for(int i=0;i<num;i++) {
            v.push_back(0);
            a.push_back(0);
        }
        if(n>0) search(0);
        return ans;
    }
};

