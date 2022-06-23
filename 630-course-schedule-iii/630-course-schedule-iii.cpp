class Solution {
public:
     
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int, vector<int>, less<int> > q;
         sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int sum=0;
        for(const vector<int>& item: courses){
            sum += item[0];  
            q.push(item[0]); 
            if(sum > item[1]){
                
                int r = q.top();
                q.pop();  
                sum = sum - r;
            }
        }
        return q.size();
     
    }
};