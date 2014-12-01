class Solution {
    private:
        unordered_map<string, int> mmap, mmap_dup, mmap2;
        unordered_map<string, int>::const_iterator got;
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            int k;
            int tmp;
            bool flag;
            int xj;
            vector<int> ans;
            vector<string> sub;
            int n;

            ans.clear();
            if(L.size()==0) return ans;
            mmap.clear();
            k = L[0].length();
            int next[S.length()/k+2];
            n = S.length();

            for(int i=0;i<L.size();i++) {
                got = mmap.find(L[i]);
                if(got==mmap.end()) {
                    mmap.insert(pair<string,int>(L[i],1));
                }
                else {
                    tmp = got->second;
                    mmap.erase(L[i]);
                    mmap.insert(pair<string,int>(L[i],tmp+1));
                }
            }
            mmap_dup = mmap;
            int pre, pos;
            for(int i=0;i<k;i++) {
                sub.clear();
                for(int j=i;j+k<=n;j+=k) {
                    sub.push_back(S.substr(j,k));
                }
                mmap2.clear();
                for(int j=0;j<sub.size();j++) {
                    got=mmap2.find(sub[j]);
                    if(got!=mmap2.end()) {
                        next[j]=got->second;
                        mmap2.erase(sub[j]);
                    }
                    else next[j]=-1;
                    mmap2.insert(pair<string,int>(sub[j],j));
                }
                string t;
                for(xj=0;xj+L.size()<=sub.size();xj++) {
                    flag = 1;
                    for(int j=0;j<L.size();j++) {
                        t = sub[xj+j];
                        got = mmap.find(t);
                        if(got!=mmap.end()) {
                            tmp = got->second;
                            mmap.erase(t);
                            if(tmp>1) mmap.insert(pair<string,int>(t,tmp-1));
                        }
                        else {
                            if(next[j+xj]>=xj) {
                                xj = next[j+xj];
                            }
                            else xj = xj+j;
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) ans.push_back(i+xj*k);
                    mmap = mmap_dup;
                }
            }
            return ans;
        }
};
