class Solution {
    public:
        int atoi(const char *str) {
            long long num=0;
            int start, sign;
            bool ff=0;
            
            start = 0;
            sign = 1;
            while(str[start]==' ') start++;
            if (str[start]=='-') {
                start++;
                sign = -1;
            }
            else if (str[start]=='+') start++;
            while(str[start]<='9' && str[start]>='0') {
                num = num * 10 + str[start]-'0';
                if(num>2147483648) break;
                ff=1;
                start ++;
            }
            if(sign == 1 && num>2147483647 ) {
                return INT_MAX;
            } 
            if(sign==-1 && num > 2147483648) {
                return INT_MIN;
            }
            if(ff) return sign*num; else return 0;
        }
};

