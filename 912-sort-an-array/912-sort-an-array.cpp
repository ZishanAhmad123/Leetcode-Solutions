class Solution {
public:
      void merge(vector<int>& nums,int low,int mid, int high){
        int n1=mid-low+1, n2=high-mid;
        int left[n1] , right[n2];
        for(int i=0; i<n1; i++)
            left[i]=nums[low+i];
        for(int i=0; i<n2; i++)
            right[i]=nums[mid+1+i];
        int i=0 , j=0 , k=low;
        while(i<n1 && j<n2){
            if(left[i]<=right[j])
                nums[k++]=left[i++];
            else 
                nums[k++]=right[j++];
        }
        while(i<n1)
            nums[k++]=left[i++];
        while(j<n2)
            nums[k++]=right[j++];
    }
    void mergesort(vector<int>& nums,int lo,int hi){
        if(lo<hi){
            int mid=lo+(hi-lo)/2;
            mergesort(nums,lo,mid);
            mergesort(nums,mid+1,hi);
            merge(nums,lo,mid,hi);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size()-1;
        mergesort(nums,0,n);
        return nums;
    
    }
};