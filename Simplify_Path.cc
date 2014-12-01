class Solution {
private:
    string p;
    string ans;
    vector<string> name;
public:
    int fetch(int x) {
        for(int i=x;i<p.length();i++) {
            if(p[i]=='/') return i;
        }
        return -1;
    }
    string simplifyPath(string path) {
        int i;
        int loc;
        string tmp;
        
        p = path + "/";
        i = 0;
        name.clear();
        while(i<p.length()) {
            if(p[i]=='/') {
                i++;
                continue;
            }
            loc = fetch(i);
            if(loc==-1) break;
            tmp = path.substr(i, loc-i);
            if(tmp==".." && !name.empty()) name.pop_back();
            if(tmp !=".." && tmp!="." && tmp.length()>0) {
                name.push_back(tmp);
            }
            i = loc+1;
        }
        ans = "";
        while(!name.empty()) {
            ans = "/" + name.back() + ans;
            name.pop_back();
        }
        if(ans=="") ans = "/";
        return ans;
    }
};

