class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int c,sum;

            sum=0;c=1;
            for(int i=digits.size()-1;i>=0;i--) {
                sum = digits[i] + c;
                digits[i]=sum%10;
                c=sum/10;
            }
            if(c!=0) {
                digits.push_back(c);
                for(int i=digits.size()-1;i>=1;i--) {
                    digits[i]=digits[i-1];
                }
                digits[0]=c;
            }
            return digits;
        }
};
