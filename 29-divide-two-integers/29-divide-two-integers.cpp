
class Solution {
public:
     void FastIO() {
 ios_base::sync_with_stdio(0);cin.tie(0);}
    
    int divide(int dividend, int divisor) {
      FastIO();
        
        
        if(divisor == -1 && dividend == INT_MIN)  // Check edge case of INT_MIN -> INT_MAX rollover
            return INT_MAX;
       
        else if (divisor == 1)   // Check if divisor is 1
            return dividend;
       
        else if(divisor == -1)   // Check if divisor is -1
           return -dividend;

        // Check if quotient will be positive or negative
        bool check = ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0));
       
        // Construct variable to store quotient
        int quotient = 0;

        // Take absolute values of integers & cast as unsigned to follow condition in while loop
        unsigned int n = abs(dividend);
        unsigned int d = abs(divisor);
        
        // Decrement dividend until <= divisor
        while(n >= d) {
            n -= d;
            quotient++;         
        }
        
        // Return signed quotient
        return check ? quotient : -quotient;             // Return signed quotient
    }
};
