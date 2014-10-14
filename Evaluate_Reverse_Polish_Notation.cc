class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            string tmp;
            int op1, op2;
            vector<int> stack;
            stack.clear();
            for(int i=0;i<tokens.size();i++) {
                tmp = tokens[i];
                if(tmp=="+" || tmp=="-" || tmp=="*" || tmp=="/") {
                    if(!stack.empty()) {
                        op2 = stack.back();stack.pop_back();
                    }
                    if(!stack.empty()) {
                        op1 = stack.back();
                        stack.pop_back();
                    }
                    switch (tmp[0]-'*') {
                        case 1: op1 = op1+op2;break;
                        case 3: op1 = op1-op2;break;
                        case 0: op1 = op1*op2;break;
                        case 5: op1 = op1/op2;break;
                    }
                    stack.push_back(op1);
                }
                else {
                    op1 = stoi(tmp);
                    stack.push_back(op1);
                }
            }
            op1 = stack.back();
            return op1;
        }
};
