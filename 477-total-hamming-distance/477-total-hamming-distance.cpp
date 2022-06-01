// class Solution {
// public:
//     int count_1 (int n){
//             int cnt=0;
//             for (int i = 0; i < 32; i++){
//                 if (n &(1 << i)) 
//                    cnt++; 
//             }
//             return cnt;
//         }
//    int hamming(int a, int b){
//        int xor1=a^b;
//        return count_1(xor1);
//    }
		
//     int totalHammingDistance(vector<int>& nums) {
        
//         int sum=0;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i; j<nums.size(); j++){
//                 sum+= hamming(nums[i], nums[j]);
//             }
//         }
//         return sum;
//     }
// };
class Solution {
 public:
     int totalHammingDistance(vector<int>& nums) {
         int res=0;
    for(int pos=0; pos<32; pos++){
        int one=0, zero=0;
        for(auto num :nums){
            if(num & (1<<pos))one++;
            else zero++;
        }
        res+=one*zero;
    }
    
    
    return res;
       }
 };