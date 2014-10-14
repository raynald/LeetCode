class Solution {
    public:
        void reverseWords(string &s) {
            char tmp;
            string result="";
            string word="";

            for(int i=0;i<s.length();i++) {
                if(s[i]==' ') {
                    if(word.length()>0) {
                        if(result=="")
                            result = word;
                        else
                            result = word + " " + result;
                    }
                    word = "";
                }
                else {
                    word += s[i];
                }
            }
            if(word.length()>0) {
                if(result=="")
                    result = word;
                else
                    result = word + " " + result;
            }
            s = result;
        }
};
