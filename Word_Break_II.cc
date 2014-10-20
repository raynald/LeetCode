class Solution {
private:
    unordered_set<string>::const_iterator got;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string tmp;
        vector<string> ans;
        vector<string> store;
        
        ans.clear();
        for(int i=s.length()-1;i>=0;i--) {   
            tmp = s.substr(i);
            got = dict.find(tmp);
            if(got!=dict.end()) {
                if(i==0) {
                    ans.push_back(tmp);
                }
                else {
                    store = wordBreak(s.substr(0,i), dict);
                    for(int j=0;j<store.size();j++) {
                        ans.push_back(store[j]+" "+tmp);
                    }
                }
            }
        }
        return ans;
    }
};
