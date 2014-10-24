class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int t1,t2;
        int ans = 0;
        unordered_map<int, bool> mmap;
        unordered_map<int, bool>::const_iterator got;
        mmap.clear();
        int n = num.size();
        for(int i=0;i<n;i++) {
            mmap.insert(pair<int, bool>(num[i], 1));
        }
        for(int i=0;i<n;i++) {
            got = mmap.find(num[i]);
            if(got->second) {
                for(int j=1;;j++) {
                    got = mmap.find(num[i]-j);
                    if(got==mmap.end()) {
                        t1 = j;
                        break;
                    }
                    mmap.erase(num[i]-j);
                    mmap.insert(pair<int,bool>(num[i]-j,0));
                }
                for(int j=1;;j++) {
                    got = mmap.find(num[i]+j);
                    if(got==mmap.end()) {
                        t2 = j;
                        break;
                    }
                    mmap.erase(num[i]+j);
                    mmap.insert(pair<int,bool>(num[i]+j,0));
                }
                if(t1+t2-1>ans) ans = t1+t2-1;
            }
        }
        return ans;
    }
};

