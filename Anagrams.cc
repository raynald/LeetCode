class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        vector<string> origin;
        unordered_map<string, string> mmap;
        unordered_map<string, string>::const_iterator got;
        map<string, bool> mop;
        map<string, bool>::iterator get;
        string tmp;
        char xx;

        origin = strs;
        for(int i=0;i<strs.size(); i++) {
            tmp = strs[i];
            for(int j=0;j<tmp.length();j++) {
                for(int k=j+1;k<tmp.length();k++) {
                    if(tmp[j]>tmp[k]) {
                        xx=tmp[j];tmp[j]=tmp[k];tmp[k]=xx;
                    }
                }
            }
            strs[i]=tmp;
        }
        mmap.clear();
        ans.clear();
        mop.clear();
        for(int i=0;i<strs.size();i++) {
            got = mmap.find(strs[i]);
            if(got==mmap.end()) {
                mmap.insert(pair<string, string>(strs[i],origin[i]));
            }
            else {
                get = mop.find(got->second);
                if(get==mop.end()) {
                    ans.push_back(got->second);
                    mop.insert(pair<string,bool>(got->second,1));
                }
                ans.push_back(origin[i]);
            }
        }
        return ans;
    }
};
