class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> sol;

sort(nums.begin(), nums.end());

for(int i=0; i<nums.size(); i++){
for(int j=i+1; j<nums.size(); j++)    {
    
	 int target2 = target - nums[i]-nums[j];
	int left = j + 1;
	int right = nums.size() - 1;

	while(left < right){
		int sum = nums[left] + nums[right];

		if(sum < target2){
			left++;
		}
		else if(sum > target2){
			right--;
		}
		else{
			vector<int> tmp = {nums[i],nums[j], nums[left], nums[right]};
			sol.push_back(tmp);

			while(left < right && nums[left] == tmp[2]) left++;
			while(left > right && nums[right] == tmp[3]) right++;
		}
	}
	while (j+1 < nums.size() && nums[j] == nums[j+1]) j++;
}
    		while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
}

return sol; 
    }
};