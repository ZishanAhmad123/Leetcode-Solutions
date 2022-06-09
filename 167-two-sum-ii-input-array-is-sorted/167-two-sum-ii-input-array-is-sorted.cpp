class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //  unordered_map<int, int>mp;
        // for (int i = 0; i < numbers.size(); i++) {
        //    int rest = target - numbers[i];
        //     if (mp.find(rest) != mp.end()) {
        //         return { mp[rest] + 1, i + 1 };
        //     }
        //     mp[numbers[i]] = i;
        // }
        // return { 1456,1071};  
        int i=0, j=numbers.size()-1;
        while(i<j){
            int val=numbers[i]+numbers[j];
            if(target==val){
                return {i+1, j+1};
            }
            else if(val <target){
                i++;
                continue;
            }
            else{
                j--;
                continue;
            }
        }
       return { 1471, 1071}; 
    }
};