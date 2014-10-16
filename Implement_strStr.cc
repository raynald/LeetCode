class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        bool flag;
        int lenh,lenn;
        if(needle[0]=='\0') return haystack;
        lenh=lenn=0;
        for(int i=0;haystack[i]!='\0';i++)
            lenh++;
        for(int i=0;needle[i]!='\0';i++)
            lenn++;
        if(lenh<lenn) return NULL;
        for(int i=0;i<=lenh-lenn;i++) {
            flag = 1;
            for(int j=0;j<lenn;j++) {
                if(needle[j]!=haystack[i+j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) return (haystack+i);
        }
        return NULL;
    }
};
