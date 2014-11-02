class Solution {
private:
    struct cmp {
        int x;
        string y;
        cmp() {}
        cmp(int u, string v):x(u),y(v) {}
        bool operator<(const cmp &s) const {
            return x>s.x;
        }
    };
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> mmap;
        unordered_map<string, vector<vector<string> > > xmap;
        vector<cmp> stack;
        cmp top;
        int ansh = 20000000;
        int cur;
        int n = start.length();
        string temp;
        string tp;
        unordered_set<string>::const_iterator got;
        unordered_map<string, int>::const_iterator gotten;
        unordered_map<string, vector<vector<string> >>::const_iterator eee;
        vector<vector<string> > ans;
        vector<vector<string> > fb;
        vector<string> tmp;

        tmp.clear();
        mmap.clear();
        xmap.clear();
        ans.clear();
        fb.clear();
        //while(!stack.empty()) stack.pop();
        stack.clear();
        tmp.push_back(start);
        fb.push_back(tmp);
        xmap.insert(pair<string, vector<vector<string> > >(start, fb));
        mmap.insert(pair<string, int>(start,0));
        stack.push_back(cmp(1,start));cur=0;
        while(cur<stack.size()) {
            top = stack[cur];cur++;
            if(top.x>=ansh) break;
            tp = top.y;
            for(int i=0;i<n;i++) {
                for(int j=1;j<=26;j++) {
                    if(tp[i]==char('a'+j-1)) continue;
                    temp=tp;
                    temp[i]=char('a'+j-1);

                    if(temp==end) {
                        ansh=top.x+1;
                    }
                    else {
                        got = dict.find(temp);
                        if(got!=dict.end()) {
                            gotten = mmap.find(temp);
                            if(gotten!=mmap.end()) {
                                if(gotten->second <top.x+1) {
                                    continue;
                                }
                            }
                            else {
                                mmap.insert(pair<string, int>(temp, top.x+1));
                                stack.push_back(cmp(top.x+1,temp));
                            }
                        }
                        else {
                            continue;
                        }
                    }
                    eee = xmap.find(tp);
                    fb=eee->second;
                    for(int k=0;k<fb.size();k++) {
                        fb[k].push_back(temp);
                    }
                    eee = xmap.find(temp);
                    if(eee!=xmap.end()) {
                        ans=eee->second;
                        for(int k=0;k<fb.size();k++) {
                            ans.push_back(fb[k]);
                        }
                        xmap.erase(temp);
                        fb=ans;
                    }
                    xmap.insert(pair<string, vector<vector<string> > >(temp, fb));
                }
            }
        }
        eee = xmap.find(end);
        if(eee!=xmap.end()) {
            ans = eee->second;
        } else ans.clear();
        return ans;
    }
};

