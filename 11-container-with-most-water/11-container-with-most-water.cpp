class Solution {
public:
    int maxArea(vector<int>& height) {
        //O(n^2)
        
        // int ans=INT_MIN;
        // for(int i=0; i<height.size(); i++){
        //     for(int j=i+1; j<height.size(); j++){
        //         int diff=j-i;
        //         int minht=min(height[i], height[j]);
        //         ans=max(ans, diff*minht);
        //     }
        // }
        // return ans;
        
        int l=0, r=size(height)-1;
        int ans=-1e9;
        while(l<r){
       int minht=min(height[l], height[r]);
            ans=max(ans, minht*(r-l));
            if(height[l]>height[r])   r--;
            else                     l++;
        }
        return ans;
        
    }
};