class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=INT_MIN;
        for(int c1=0;c1<m;c1++){ 
            vector<int> v(n,0);
            for(int c2=c1;c2<m;c2++){
                for(int i=0;i<n;i++){
                    v[i]+=matrix[i][c2];   // finding row-wise sum of the current sub-matrix
                }
                int sum=0;
                set<int> st;
                st.insert(0);
                for(int r=0;r<n;r++){     // finding maximum subarray sum less than k
                    sum+=v[r];
                    auto it=st.lower_bound(sum-k);
                    if(it!=st.end()){
                        ans=max(ans,sum-(*it));
                    }
                    st.insert(sum);
                }
            }
        }
        return ans;
    }
};