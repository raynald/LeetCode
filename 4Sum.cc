struct tup {
    int x;
    int y;
    int sum;
    tup () {}
    tup (int a, int b, int c): x(a), y(b), sum(c) {}
};
bool operator<(const tup &x, const tup &y) {
    return x.sum<y.sum || (x.sum==y.sum && x.x<y.x)|| (x.sum==y.sum && x.x==y.x && x.y<y.y);
}
class Solution {
    private:
        vector<tup> BigSet;
        vector<int> tmp;
        vector<int> nu;
        vector<vector<int> > ans;
    public:
        void find(int ind, int x, int left, int right) {
            if(left>right) return;
            int mid = (left+right)/2;
            if(BigSet[mid].sum<x) {
                find(ind, x, mid+1, right);
                return;
            }
            if(BigSet[mid].sum>x) {
                find(ind, x, left, mid-1);
                return;
            }
            if(BigSet[mid].x<BigSet[ind].y+1) {
                find(ind, x, mid+1, right);
                return;
            }
            if(BigSet[mid].sum==x) {
                find(ind, x, left, mid-1);
                if(!tmp.empty() && nu[BigSet[ind].x]==tmp[0] && nu[BigSet[ind].y]==tmp[1] && nu[BigSet[mid].x] == tmp[2]) {}
                else{
                    tmp.clear();
                    tmp.push_back(nu[BigSet[ind].x]);
                    tmp.push_back(nu[BigSet[ind].y]);
                    tmp.push_back(nu[BigSet[mid].x]);
                    tmp.push_back(nu[BigSet[mid].y]);
                    ans.push_back(tmp);          
                }
                find(ind, x, mid+1, right);
                return;
            }
        }
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            int n;

            sort(num.begin(), num.end());
            nu = num;
            n=num.size();
            ans.clear();
            BigSet.clear();
            for(int i=0;i<n;i++) {
                for(int j=i+1;j<n;j++) {
                    BigSet.push_back(tup(i, j, num[i]+num[j]));
                }
            }
            sort(BigSet.begin(),BigSet.end());
            for(int i=0;i<BigSet.size();i++) {
                if(i>0 && nu[BigSet[i].x]==nu[BigSet[i-1].x] && nu[BigSet[i].y]==nu[BigSet[i-1].y]) continue;
                find(i, target-BigSet[i].sum, i+1, BigSet.size()-1);
            }
            return ans;
        }
};
