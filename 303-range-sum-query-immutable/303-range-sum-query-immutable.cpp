class NumArray {
public:

    vector<int> v;
    NumArray(vector<int>& nums) {
	
        for(int i:nums){
            v.push_back(i);
        }
    }
    int sumRange(int left, int right) {
        int s=accumulate(v.begin()+left,v.begin()+1+right,0);
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */