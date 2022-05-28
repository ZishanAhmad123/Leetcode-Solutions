class Solution {
public:
    string intToRoman(int num) {
      vector<pair<int,string>>v;
        v.push_back(make_pair(1000,"M"));
        v.push_back(make_pair(900,"CM"));
        v.push_back(make_pair(500,"D"));
        v.push_back(make_pair(400,"CD"));
        v.push_back(make_pair(100,"C"));
        v.push_back(make_pair(90,"XC"));
        v.push_back(make_pair(50,"L"));
        v.push_back(make_pair(40,"XL"));
        v.push_back(make_pair(10,"X"));
        v.push_back(make_pair(9,"IX"));
        v.push_back(make_pair(5,"V"));
        v.push_back(make_pair(4,"IV"));
        v.push_back(make_pair(1,"I"));
        
        string ans="";
        for(auto i:v){
            int temp = num/i.first;
           
                while(temp--){
                    ans+=i.second;
                }
                num%=i.first;
         
            // if(num==0)
            //     break;
        }
        
        return ans;   
    }
};