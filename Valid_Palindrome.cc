class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return 1;
        string dup="";
        for(int i=0;i<s.length();i++) {
            if(s[i]>='A' && s[i] <='Z') dup+='a'+s[i]-'A';
            if (s[i]>='a' && s[i]<='z') dup+=s[i];
            if(s[i]>='0' && s[i]<='9') dup+=s[i];
        }
        for(int j=0;j<(dup.length()+1)/2;j++) {
            if(dup[j]!=dup[dup.length()-1-j]) return 0;
        }
        return 1;
    }
};
