class Solution {
private:
    string p;
    string ans;
    vector<string> name;
public:
    void search(int x, int y) {
        int i, j;
        bool flag;
        string tmp;
        for(i=y;p[i]=='/' && i<p.length();i++);
        flag = 0;
        for(j=i+1;j<p.length();j++)
            if(p[j]=='/') {flag = 1;break;}
        if(!flag) {
            if(i<p.length()) tmp = p.substr(i); else tmp="";
            if(tmp==".") {
                for(int w=0;w<x;w++) 
                    if(w<name.size()) ans+="/"+name[w]; 
                if(ans=="") ans="/";
            }
            else if(tmp=="..") {
                for(int w=0;w<x-1;w++) 
                    if(w<name.size()) ans+="/"+name[w]; 
                if(ans=="") ans="/";
            }
            else {
                if(i<p.length()) {
                    if(name.size()>x) name[x]=p.substr(i,j-i);
                    else {
                        name.push_back(p.substr(i,j-i));
                    }
                }
                else x--;
                for(int w=0;w<=x;w++)
                    if(w<name.size()) ans+="/"+name[w];
                if(ans=="") ans="/";
            }
        }
        else {
            if(p[i]=='.' && j==i+1) search(x,j);
            else if(p[i]=='.' && p[i+1]=='.' && j==i+2) if(x>1) search(x-1, i+2); else search(0,i+2);
            else {
                if(name.size()>x) name[x]=p.substr(i,j-i);
                else {
                    name.push_back(p.substr(i,j-i));
                }
                search(x+1, j);
            }
        }
    }
    
    string simplifyPath(string path) {
        p = path;
        ans="";
        name.clear();
        search(0, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("///")<<endl;
    cout << sol.simplifyPath("/home//foo/")<<endl;
    cout << sol.simplifyPath("/a/./b/../../c/")<<endl;
    cout << sol.simplifyPath("/.")<<endl;
    cout << sol.simplifyPath("/..")<<endl;
    cout << sol.simplifyPath("/.../")<<endl;
    cout << sol.simplifyPath("/a/../../")<<endl;
    cout << sol.simplifyPath("/a/./b/../../c/")<<endl;
    cout << sol.simplifyPath("/home/of/foo/../../bar/../../is/./here/.")<<endl;
    return 0;
}
