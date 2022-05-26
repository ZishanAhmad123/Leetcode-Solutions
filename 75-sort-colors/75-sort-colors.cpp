class Solution
{
    public:
    // selection sort
        void sortColors(vector<int> &nums){
//         for(int i=0;i<nums.size()-1;i++){
            
//             int min_position=i; //let it be the minimum element's position
            
//             //then find the minimum element other than this min_position element.
//             for(int j=i;j<nums.size();j++){
                
//                 if(nums[j]<nums[min_position])
//                     min_position=j;
//             }
//             //than swap the minimum element with the older minimum element. 
//             swap(nums[min_position],nums[i]);
//         }
            // Bubble sort
            for(int i=0; i<nums.size()-1; i++){
                for(int j=0; j<nums.size()-1-i; j++){
                    if(nums[j]>nums[j+1])
                        swap(nums[j], nums[j+1]);
                }
            }
    }
};