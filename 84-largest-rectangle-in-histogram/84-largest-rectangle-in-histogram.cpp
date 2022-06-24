class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
     int n = arr.size();
        
        int maxi = INT_MIN;
        
        vector<int> left(n);
        
        vector<int> right(n);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = st.top() + 1;
            }
            
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                right[i] = n - 1;
            }
            else
            {
                right[i] = st.top() - 1;
            }
            
            st.push(i);
        }
        
        for(int i = 0; i < n; i++)
        {
            int area = arr[i] * (right[i] - left[i] + 1);
            
            maxi = max(maxi, area);
        }
        
        return maxi;   
    }
};