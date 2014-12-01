class Solution {
    private:
        map<char, int> mmap;
        map<char, int>::iterator got;
    public:
        int lengthOfLongestSubstring(string s) {
            int i, j, ans;

            mmap.clear();
            i = j = 0;
            ans = 0;
            while(j<s.length()) {
                got = mmap.find(s[j]);
                if(got!=mmap.end()) {
                    if(j-i>ans) ans=j-i;
                    if(got->second+1>i) i = got->second+1;
                    mmap.erase(s[j]);
                }
                mmap.insert(pair<char,int>(s[j],j));
                j++;
            }
            if(j-i>ans) ans = j-i;
            return ans;
        }
};
