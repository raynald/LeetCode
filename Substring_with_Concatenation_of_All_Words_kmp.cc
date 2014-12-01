class Solution {
private:
    unordered_map<string, int> mmap, mmap_dup;
    unordered_map<string, int>::const_iterator got;
public:
    void build(string S, int next[]) {
        T[0]=-1;
        T[1]=0;
        int pos, pre;
        pos = 2;
        pre = 0;
        while(pos<S.length()) {
            if(S[pos]==S[pre]) {
                pre ++;
                next[pos]=pre;
                pos++;
            }
            else {
                if(pre>0) pre=next[pre];
                else {
                    next[pos]=0;
                    pos ++;
                }
            }
        }
    }

    vector<int> findSubstring(string S, vector<string> &L) {
        int k;
        int tmp;
        bool flag;
        vector<int> ans;
        ans.clear();
        if(L.size()==0) return ans;
        int T[S.length()+1];
        build(S, T);
        mmap.clear();
        k = L[0].length();
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
        int pos = 0;
        int pos_i = 0;
        string t;
        while (pos+pos_i < S.lenth()) {
            flag = 1;
            if(pos + L.size()*k>S.length()) break;
            for(int j=0;j<L.size();j++) {
                t = S.substr(i+j*k, k);
                got = mmap.find(t);
                if(got==mmap.end()) {
                    flag = 0;
                    break;
                }
                tmp = got->second;
                mmap.erase(t);
                if(tmp>1) mmap.insert(pair<string,int>(t,tmp-1));
            }
            if(flag) ans.push_back(i);
            mmap = mmap_dup;
        }
        return ans;
    }
};

