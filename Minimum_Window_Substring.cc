#include"head.h"

class Solution {
private:
        int cur['z'-'0'+1];
        int a['z'-'0'+1];
public:
    bool check() {
        for(int k=0;k<='z'-'0';k++)
            if(a[k]>cur[k]){
                return 0;
            }
        return 1;
    }

    string minWindow(string S, string T) {
        int n, m, j;
        int ans;
        string ret="";
        n = S.length();
        m = T.length();
        ans = n+1;
        int next[n+2];
        memset(a,0,sizeof(a));
        memset(cur,-1,sizeof(cur));
        memset(next,-1,sizeof(next));
        for(int i=0;i<m;i++) {
            a[T[i]-'0']++;
        }
        for(int i=0;i<n;i++) {
            if(a[S[i]-'0']==0) continue;
            if(cur[S[i]-'0']>=0) {
                next[cur[S[i]-'0']] = i;
                cur[S[i]-'0']=i;
            }
        }
        memset(cur,0,sizeof(cur));j=-1;
        for(int i=0;i<n;i++) {
            if(a[S[i]-'0']==0) continue;
            if(check()) {
                    if(j-i+1<ans) {
                        ans = j-i+1;
                        ret = S.substr(i,ans);
                    }
            }
            else {
                if(j>=n-1) break;
                j++;
                for(;j<n;j++) {
                    cur[S[j]-'0']++;
                    if(check()) {
                        if(j-i+1<ans) {
                            ans = j-i+1;
                            ret = S.substr(i,ans);
                        }
                        break;
                    }
                }
            }
            if(cur[S[i]-'0'] == a[S[i]-'0'] && next[i]>j) {
                for(int k=j+1;k<=next[i];k++)
                    cur[S[k]-'0']++;
                j = next[i];
            }
            cur[S[i]-'0']--;
        }
        return ret;
    }
};


int main() {
    Solution sol;
    cout << sol.minWindow("a", "a")<<endl;
   cout << sol.minWindow( "mspkqlcdmrwgrmcaytxilusinwgjvkdhfuuvfwarpxaglegjyftlblvqjezhqeovyisfgtxvqzdbdlmbthowumnfqomitbetlyzsrwpjvvkygycbfsyzgnfwbrhwunqilpadnrmkmzkvzowfhwgnjnmlftjbgzjtolwddlnrmymlmlsvhzltmzgtspvapetfqsjvfymrybelmxivwtokuueokbobhkgzerujqjcomgbadmxbhmociuquvhxereexvainlkcxsfxyrvzzjpbtjrqgynlrtpqrryedkiadqabhxcigslbdftkfhvxcmptdoagykjdajekgjsodgrgllqqulpwzfsdvsjtcszfddplojbrptyagqtaeiydnqgiksepmduqildxwfqmaqoghhilqiqfbxqlrucdzythlzgiexwepkmwuwjmeatfzjtqfxtewpohourutnajamhwiriotbwsnpismdxkunskhjedzeozsvvaofrhinzvcjoqpnbjavwjgcohjcgbadeokvytizomjeearhlrchdlkrstwbwwgamrxkkhkatvfavwhgqmqvzamrviutebutstfcbpcwmjwjigqyuittkhmfqhywkupcqvgrmkpbumkcuacokxhuevzwcatmwkqmhwfwjvxfjhhdkltuicpoxqlcsgqpshdafjwqevvpcesmpljzpyomqbqjjhabqddvozoswjhzobndowfdwvsnwiwhryihbmfqntkkculsxyyoxdrtyliwwgdnenvgbcypvkbzgmsemqujvlftzprvwwialfinjieetfgbtahhqbtlnagop", "zjlxtmibwxkfbraixbdx")<<endl;
    cout<<sol.minWindow("ADOBECODEBANC","ABC")<<endl;
    return 0;
}
