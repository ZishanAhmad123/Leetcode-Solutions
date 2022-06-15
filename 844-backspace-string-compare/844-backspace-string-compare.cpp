class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string result1="";
        string result2="";
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]>='a' and s[i]<='z')
            {
                result1.push_back(s[i]);
            }
            else if(!result1.empty())
            {
                result1.pop_back();
            }
            i++;
        }
        i=0;
         while(t[i]!='\0')
        {
            if(t[i]>='a' and t[i]<='z')
            {
                result2.push_back(t[i]);
            }
            else if(!result2.empty())
            {
                result2.pop_back();
            }
            i++;
        }
        return result1==result2; 
    }
};