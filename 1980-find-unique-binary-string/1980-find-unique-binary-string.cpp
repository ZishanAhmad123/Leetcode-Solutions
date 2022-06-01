class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
          set<string> st;
        for(auto str : nums){
            st.insert(str);
        }
        
        int n = nums[0].length();
      
        
        string temp = "";
        char mask;
        for(int i = 0; i <(1<<n); i++){
            for(int j = n - 1; j >= 0; j--){
                mask = (((i >> j) & 1) + '0');
                temp += mask;
            }
            if(st.find(temp) == st.end()){
                return temp;
            }
            temp = "";
        }
        
         return " ";       // this return will never execute
    }
};