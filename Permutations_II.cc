class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            int n;
            int pos;
            int ans;
            int tmp;
            vector<vector<int> > sum;

            sum.clear();
            n= num.size();
            if(n==0) return sum;
            sort(num.begin(),num.end());
            while(1) {
                sum.push_back(num);
                pos = -1;
                for(int i=n-2;i>=0;i--) {
                    if(num[i]<num[i+1]) {
                        pos = i;
                        break;
                    }
                }
                if(pos==-1) break;
                ans = -1;
                for(int i=pos+1;i<n;i++) {
                    if(ans == -1 || num[i]>num[pos] && num[i]<num[ans]) {
                        ans = i;
                    }
                }
                tmp=num[pos];num[pos]=num[ans];num[ans]=tmp;
                sort(num.begin()+pos+1, num.end());
            }        
            return sum;        
        }
};


