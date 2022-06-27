class Solution {
public:
    int minPartitions(string s) {
        int max_digit=0;
        for(auto digit : s){
            max_digit=max(digit-'0', max_digit);
        }
        return max_digit;
    }
};