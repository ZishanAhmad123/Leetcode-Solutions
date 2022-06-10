class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int> freq(128);
        //start from index 0 and now left and right both are 0
        int left = 0;
        int right = 0;
        int ans = 0;//here we will store the length of the longest substring without repeating characters
        while (right < s.length()) //until the right reaches the end of the string, keep going
        {
            char r = s[right]; //store character at right index in r
            freq[r]++; //update the frequency in the frequency vector
            while (freq[r] > 1){
            /*once you see that the frequency of the rightmost character becomes more than 1,
            stop aquiring and start releasing from the left until your freq becomes exactly 1*/
                char l = s[left]; //now store the leftmost character in the character l 
                freq[l]--; //and now decrement the frequency by 1 as we have dropped off that character from our window.
                left++; //increment left as the new window is shifted one place towards the right.
            }
            //update your answer by the size of your window between right and left and store the max of the current ans and the new one.
            ans = max(ans, right - left + 1);
            //increment your right pointer too and keep on doing the same work
            right++;
        }
        //at the end return your answer
        return ans;
    }
};