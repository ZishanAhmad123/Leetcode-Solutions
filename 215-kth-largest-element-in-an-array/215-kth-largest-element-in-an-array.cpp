class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int i=1, ans=0;
        while(!pq.empty()){
            if(i==k){
                ans=pq.top();
                break;
            }
            i++;
            pq.pop();
        }
        return ans;
    }
};