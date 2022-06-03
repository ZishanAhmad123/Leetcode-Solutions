class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int>v,ans;
        for(int i=0;i<=nums.size();i++){
            v.push_back(-1);
        }
        for(int i=0;i<nums.size();i++){
            v[nums[i]]=0;
        }
        for(int i=1;i<=nums.size();i++){
            if(v[i]==-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};