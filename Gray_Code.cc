class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> a;
        int power;
        
        a.clear();
        a.push_back(0);
        if(n==0) return a;
        power=1;
        for(int i=1;i<=n;i++) {
            for(int j=a.size()-1;j>=0;j--) {
                a.push_back(a[j]+ power);
            }
            power*=2;
        }
        return a;
    }
};
