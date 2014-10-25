class Solution {
    private:
        enum Type {
            Space=0,
            Sign=1,
            Digit=2,
            Dot=3,
            Exp=4,
            Null=-1};
        Type inputType;
    public:
        bool isNumber(const char *s) {
            int states[5][9] = {  
                {0, 8, -1, -1, 8, -1, -1, 8, 8},  
                {2, -1, -1, -1, -1, 6, -1, -1, -1},  
                {1, 1, 1, 4, 4, 7, 7, 7, -1},  
                {3, 4, 3, -1, -1, -1, -1, -1, -1},  
                {-1, 5, -1, -1, 5, -1, -1, -1, -1}  
            };  
            int state = 0;
            for(int i = 0;s[i]!='\0'; i++) {
                inputType = Null;
                if(s[i] == ' ') {
                    inputType = Space;
                } else if(s[i] == '+' || s[i] == '-') {
                    inputType = Sign;
                } else if (s[i] >='0' && s[i] <= '9') {
                    inputType = Digit;
                } else if (s[i] == '.') {
                    inputType = Dot;
                } else if (s[i] == 'e' || s[i]  == 'E') {
                    inputType = Exp;
                } else {
                    return false;
                }
                state = states[inputType][state];
                if (state < 0) {
                    return false;
                }
            }
            return (state ==1 || state ==4 || state==7 || state==8);
        }
};

