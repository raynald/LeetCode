class Solution {
public:
    string multiply(string num1, string num2) {
        int n,m;
        char tmp;
        n = num1.length();
        m = num2.length();
        int digit[n+m];
        int c;
        int sum;
        string ans;
        int s;
        
        memset(digit,0,sizeof(digit));
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                digit[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        c=0;
        ans = "";
        for(int i=n+m-2;i>=0;i--) {
            sum = digit[i]+c;
            digit[i]=sum%10;
            ans = char('0' + digit[i])+ans;
            c = sum/10;
        }
        while(c!=0) {
            ans = char('0' + (c%10))+ ans;
            c = c/10;            
        }
        for(s=0;s<ans.length()-1 && ans[s]=='0';s++);
        return ans.substr(s);
    }
};
