class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>masks(n);
       
        for(int i=0; i<n; i++){
             int mask=0;
         for( auto ch: words[i]) {
             mask=(mask |(1<<(ch-'a')));
         } 
            masks[i]=mask;
        }
        int maxi=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int inter=(masks[i] & masks[j]);  //  it give common char 
                if(inter==0){                 // if  common freq ==0  then we have to calculate our result
                int prod = words[i].size()*words[j].size();
                  maxi=max(maxi,prod );
                 }
            }
        }
      return maxi;
    }
};