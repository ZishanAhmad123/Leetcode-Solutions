class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());         //sorting the elements
        
        int l, r, f=0, ans;
        for(int i=0;i<nums.size();i++)
        {  
		    //making one element fixed and setting a target for other two elements
			// a + b + c = target    ->    a + b = target - c = t
            int t = target - nums[i];              
			
			//considering all elements after the current one because if we'll take all elements then many operations will be repeated
            l=i+1; r=nums.size()-1;
            int sum = 0;
            
            while(l<r)
            {
                sum=nums[l]+nums[r];         //sum of two elements
                
				//update the ans if current closet of 3 elements make the sum nearest to target than previous ans 
                if(abs(target - sum - nums[i]) < abs(target - ans))
                        ans=sum+nums[i];
                
                if(sum==t)        //we get the sum = target, hence no need to proceed further
                {
                    f=1;
                    break;
                }
                else if(sum > t)     //if sum is greater than target then move right pointer 1 step back
                    r--;
                else                      //if sum is smaller then move left pointer 1 step ahead
                    l++;
            }
            
            if(f)
                break;
        }
        return ans; 
    }
};