class Solution {
public:
   
    
    string largestPalindromic(string num) {
        vector<int>freqArr(10);
        for(char i:num)freqArr[i - '0']++; 
        
        string front = "", back = ""; // Intiliasing two empty strings 
        
        for(int i = 9;i>=0;i--) // starting the loop in the reverse as we need to create largest palindrome number
        {

            if(i == 0 && front.empty()) // skips leading zeros
                continue;
           
            while(freqArr[i] >=2 ) 
            {
                front += to_string(i);
                back += to_string(i);
                freqArr[i] -= 2;
            }
        }
        
        for(int i = 9;i>=0;i--)
        {
            if(freqArr[i]) 
            {
                front += to_string(i);
                break;
            }
        }
      //  cout<< front<<back<<endl;
        
        reverse(back.begin(),back.end());
        
        return front + back ;
    }
};