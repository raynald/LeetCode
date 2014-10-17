class Solution {
private:
    int n;
    vector<string> vec;
    vector<int> ch;
    string a[10];

public:
    void search(string ori, int x) {
        string str;
        if(x==n+1) {
            str="";
            for(int i=0;i<=n;i++) {
                str+=a[ori[i]-'0'][ch[i]];
            }
            vec.push_back(str);
        }
        else {
            for(int i=0;i<a[ori[x]-'0'].length();i ++) {
                ch.push_back(i);
                search(ori, x+1);
                ch.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        a[0]="";
        a[1]="";
        a[2]="abc";
        a[3]="def";
        a[4]="ghi";
        a[5]="jkl";
        a[6]="mno";
        a[7]="pqrs";
        a[8]="tuv";
        a[9]="wxyz";
        
        n=digits.length() - 1;
        vec.clear();
        ch.clear();
        search(digits, 0);
        return vec;
    }
};
