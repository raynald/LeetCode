class Solution {
public:

    int longestValidParentheses(string s) {
        int stack = 0;
        int ans, sum, ans2, sum2;
        
        ans = sum = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') stack++;
            else {
                if(stack>0) {
                    stack--;
                    ans+=2;
                    if(stack==0 && ans>sum) sum=ans;
                }
                else {
                    ans = 0;
                }
            }
        }
        ans = 0;stack=0;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i]==')') stack++;
            else {
                if(stack>0) {
                    stack--;
                    ans+=2;
                    if(stack==0 && ans>sum) sum=ans;
                }
                else {
                    ans = 0;
                }
            }
        }
        return sum;
    }
};
