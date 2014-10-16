class Solution {
public:
    int sqrt(int x) {
        long long y;
        long long t = x;
        y = 1;
        while(1) {
            if(y*y<=t && (y+1)*(y+1)>t) return y;
            y = (y+t/y)/2;
        }    
    }
};
