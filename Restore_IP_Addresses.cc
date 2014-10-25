class Solution {
    private:
        int a[4];
        vector<string> ans;
        string origin;

    public:
        void search(int x, string s) {
            if(x==4) {
                if(s.length()==0) {
                    string tmp = origin.substr(0,a[0])+"."+origin.substr(a[0],a[1])+"."+origin.substr(a[0]+a[1],a[2])+"."+origin.substr(a[0]+a[1]+a[2]);
                    ans.push_back(tmp);
                }
                return;
            }
            a[x]=1;
            if(s.length()>=1) search(x+1, s.substr(1));
            a[x]=2;
            if(s.length()>=2 && s[0]!='0') search(x+1, s.substr(2));
            a[x]=3;
            if(s.length()>=3 && atoi(s.substr(0,3).c_str())<=255 && s[0]!='0') search(x+1, s.substr(3));
        }

        vector<string> restoreIpAddresses(string s) {
            origin = s;
            ans.clear();
            search(0, s);
            return ans;
        }
};

