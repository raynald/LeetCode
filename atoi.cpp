class Solution {
    public:
        int atoi(const char *str) {
            start = 0;
            sign = 1;
            while(str[start]==' ') start++;
            if (str[start]=='-') {
                start++;
                sign = -1;
            }
            if (str[start]=='+') start++;
            while(str[start]<='9' && str[start]>='0') {
                num = num * 10 + str[start]-'0';
                start ++;
            }
        }
};
