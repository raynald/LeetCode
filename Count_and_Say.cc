class Solution {
public:
    string countAndSay(int n) {
        char ch;
        int count;
        string ans;
        
        if(n==0) return "";
        if(n==1) return "1";
        string tmp = "1";
        for(int i=2;i<=n;i++) {
            ch = tmp[0];
            count = 1;
            ans = "";
            for(int j=1;j<tmp.length();j++) {
                if(tmp[j]==ch) count ++;
                else {
                    ans += to_string(count) + ch;
                    count = 1;
                    ch = tmp[j];
                }
            }
            ans += to_string(count) + ch;
            tmp = ans;
        }
        return tmp;
    }
};
