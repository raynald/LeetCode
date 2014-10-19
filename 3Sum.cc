class Solution {
    public:
        bool find(vector <int> &num, int left, int right, int x) {
            if(left>right)return 0;
            int mid=(left+right)/2;
            if(num[mid]==x) return 1;
            if(num[mid]<x) return find(num, mid+1, right, x);
            if(num[mid]>x) return find(num, left, mid-1, x);
        }
        vector<vector<int> > threeSum(vector<int> &num) {
            int n = num.size();
            vector<int> tmp;
            vector<vector<int>> ans;
            int sum;

            ans.clear();
            if(n==0) return ans;
            sort(num.begin(), num.end());
            for(int i=0;i<n; i ++) {
                if(i>0 && num[i]==num[i-1]) continue;
                for(int j=i+1;j<n;j++) {
                    if(j>i+1 && num[j]==num[j-1]) continue;
                    sum = num[i]+num[j];
                    if(find(num, j+1, n-1, -sum)) {
                        tmp.clear();
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(-sum);
                        ans.push_back(tmp);
                    }
                }
            }
            return ans;
        }
};
