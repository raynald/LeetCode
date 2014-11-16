class Solution {
public:
    void compute(char *W, int next[]) {
        int pos = 2;
        int pre = 0;
        next[0] = -1;
        next[1] = 0;
        while(pos < strlen(W)) {
            if(W[pos-1] == W[pre]) {
                pre ++;
                next[pos] = pre;
                pos++;
            }
            else {
                if(pre>0) pre = next[pre];
                else {
                    next[pos] = 0;
                    pos ++;
                }
            }
        }
    }
    
    int strStr(char *haystack, char *needle) {
        int pos = 0;
        int pos_i = 0;
        int next[strlen(needle)];

        if(strlen(haystack)<strlen(needle)) return -1;
        if(strlen(needle)==0) return 0;
        compute(needle, next);
        while (pos + pos_i < strlen(haystack)) {
            if(haystack[pos + pos_i] == needle[pos_i]) {
                if(pos_i == strlen(needle)-1) return pos;
                pos_i ++;
            }
            else {
                if(next[pos_i] > -1) {
                    pos = pos + pos_i - next[pos_i];
                    pos_i = next[pos_i];
                }
                else {
                    pos_i = 0;
                    pos ++;
                }
            }
        }
        return -1;
    }
};
