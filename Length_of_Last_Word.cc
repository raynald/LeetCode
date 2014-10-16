class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int ans = 0;
        bool flag = 0;
        int length=0;
        for(int i=0;s[i]!='\0';i++) 
            length++;
        for(int i=length-1;i>=0;i--) {
            if(!flag && s[i] == ' ') continue;
            if(s[i]!=' ') {
                flag = 1;
                ans ++;
            }
            else {
                return ans;
            }
        }
        return ans;
    }
};
