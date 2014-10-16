class Solution {
public:
    string addBinary(string a, string b) {
        string out="";
        int c=0;
        int sum;
        
        if(a.length()<b.length()) {
            out = a;
            a = b;
            b = out;
        }
        int tmp=a.length()-b.length();
        for(int i=1;i<=tmp;i++)
            b = "0" + b;
        cout << a << " " << b << endl;
        out = "";
        for(int i=a.length()-1;i>=0;i--) {
            sum = a[i]-'0'+b[i]-'0'+c;
            if(sum%2) out="1"+out; else out = "0" + out;
            c = sum / 2;
        }
        if(c==1) out = "1" + out;
        return out;
    }
};
