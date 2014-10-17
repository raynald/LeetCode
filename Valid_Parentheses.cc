class Solution {
    public:
        bool isValid(string s) {
            vector<int> stack;
            int top;

            stack.clear();
            for(int i=0;i<s.length();i++) {
                if(s[i]=='(') stack.push_back(1);
                if(s[i]=='{') stack.push_back(2);
                if(s[i]=='[') stack.push_back(3);
                if(s[i]==')') {
                    if(stack.empty()) return false;
                    top = stack.back();
                    if(top!=1) return false;
                    stack.pop_back();
                }
                if(s[i]=='}') {
                    if(stack.empty()) return false;
                    top = stack.back();
                    if(top!=2) return false;
                    stack.pop_back();
                }
                if(s[i]==']') {
                    if(stack.empty()) return false;
                    top = stack.back();
                    if(top!=3) return false;
                    stack.pop_back();
                }
            }
            if(stack.empty()) return 1; else return 0;
        }
};
