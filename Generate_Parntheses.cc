class Solution {
private:
    vector<string> sum;
    int length;
public:
    void search(string ans, vector<int> vec, int x) {
        vector<int> sec = vec;
        vector<int> sec2 = vec;
        
        if(!vec.empty()) {
            sec.pop_back();
            search(ans + ")", sec, x);
        }
        if(x<=length) {
            sec2.push_back(x);
            search(ans + "(", sec2, x+1);
            return;
        }
        if(vec.empty() && x>length) sum.push_back(ans);
    }
    vector<string> generateParenthesis(int n) {
        length = n;
        vector<int> v;
        v.clear();
        sum.clear();
        search("", v, 1);
        return sum;
    }
};
