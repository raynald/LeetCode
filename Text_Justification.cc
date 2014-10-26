class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        string tmp;
        int j;
        int len;
        vector<int> blank;
    
        for(int i=0;i<words.size();i++) {
            tmp = words[i];
            len = tmp.length();
            blank.clear();
            for(j=1;i+j<words.size();j++) {
                if(len+1+words[i+j].length()>L) break;
                blank.push_back(1);
                len=len+1+words[i+j].length();
            }
            if(j==1) {
                   for(int k=1;k<=L-len;k++) tmp+=" ";
            }
            else {
                if(i+j==words.size()) {
                    for(int k=1;k<j;k++) {
                        tmp+=" ";
                        tmp += words[i+k];
                    }
                    for(int k=1;k<=L-len;k++) tmp+=" ";
                }
                else {
                    for(int k=1;k<j;k++) {
                        blank[k-1]+=(L-len)/(j-1);
                    }
                    for(int k=1;k<=(L-len)%(j-1);k++) {
                       blank[k-1]++;
                    }
                    for(int k=1;k<j;k++) {
                        for(int l=1;l<=blank[k-1];l++) tmp+=" ";
                        tmp += words[i+k];
                    }
                }
                for(int k=1;i+j+k-1<words.size();k++) {
                    words[i+k]=words[i+j+k-1];
                }
                for(int k=1;k<=j-1;k++) words.pop_back();
            }
            words[i]=tmp;
        }
        return words;
    }
};
