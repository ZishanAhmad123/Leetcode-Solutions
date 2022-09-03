class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        
        int sum = 0;
        
        int steps = 0;
        
        while(sum < target)
        {
            sum += steps;
            
            steps++;
        }
        
        while((sum - target) % 2 == 1)
        {
            sum += steps;
            
            steps++;
        }
        
        return steps - 1;
    }
};