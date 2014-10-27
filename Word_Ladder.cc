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
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            priority_queue<cmp> stack;
            cmp top;
            int n = start.length();
            string temp;
            unordered_set<string>::const_iterator got;

            while(!stack.empty()) stack.pop();
            stack.push(cmp(1,start));
            while(!stack.empty()) {
                top = stack.top();
                stack.pop();
                for(int i=0;i<n;i++) {
                    for(int j=1;j<=26;j++) {
                        if(top.y[i]==char('a'+j-1)) continue;
                        temp = top.y;
                        temp[i]=char('a'+j-1);
                        if(temp==end) return top.x+1;
                        got = dict.find(temp);
                        if(got!=dict.end()) {
                            stack.push(cmp(top.x+1,temp));
                            dict.erase(temp);
                        }
                    }
                }
            }
            return 0;
        }
};
