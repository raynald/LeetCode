class Solution {
    private:
        int n;
        vector<vector<int> > ans;
        vector<int> val;
        vector<int> a;
    public:
        void search(int x, int y) {
            if (y==0) {
                vector<int> sum;
                sum.clear();
                for(int i=0;i<x;i++) {
                    if(a[i]) sum.push_back(val[i]);
                }
                if(sum.size()>0) ans.push_back(sum);
                return;
            }
            if(x>=n) return;
            if(val[x]<=y) {
                a[x]=0;
                search(x+1, y);
                a[x]=1;
                if(x>=1 && a[x-1]==0 && val[x]==val[x-1]) return;
                search(x+1, y-val[x]);
            }
        }
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            ans.clear();
            n = num.size();
            val=num;a=num;
            search(0, target);
            return ans;
        }
};
