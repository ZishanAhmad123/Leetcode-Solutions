 class Solution {
  public:
int uniqueMorseRepresentations(vector<string>& words) {
    
// all the Morse Code  given  
string code[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

set<string>st;
 for(int i=0;i<words.size();i++){
        string s="";
     //for every word calculated Morese code
        for(int j=0;j<words[i].size();j++){
            s+=code[words[i][j]-'a'];
        }
     // insert it into set
       st.insert(s);
    }

    //return the size of set
return st.size();
    
   }
 };