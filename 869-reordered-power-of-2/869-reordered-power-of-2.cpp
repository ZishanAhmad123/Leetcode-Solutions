class Solution {
public:
    vector<int> cntfreq(int n){
        vector<int>cntArray(10, 0);
        while(n>0){
            cntArray[n%10]++;
            n=n/10;
        }
        return cntArray;
    }
    
    bool camp(vector<int>cnt1, vector<int>cnt2){
        for(int i=0; i<cnt1.size(); i++){
            if(cnt1[i]!=cnt2[i])return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>cntarray=cntfreq(n);
        
        for(int i=0; i<31; i++){
            int powerof2=pow(2,i);
           vector<int> powerof2freq= cntfreq(powerof2);
            if(camp(cntarray, powerof2freq))return true;
        }
        return false;
    }
};