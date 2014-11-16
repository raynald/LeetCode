class Solution {
    private:
        string longest;
    public:
        void check(string s, int left, int right) {
            while(left>=0 && right<s.length() && s[left]==s[right]) {
                left--;
                right++;
            }
            if(right-left-1>longest.length()) {
                longest = s.substr(left+1, right-left-1);
            }
        }

        string longestPalindrome(string s) {
            if(s.length()==0) return s;
            longest=s[0];
            for(int i=0;i<s.length()-1;i++) {
                check(s, i, i);
                check(s, i, i+1);
            }
            return longest;
        }
};
