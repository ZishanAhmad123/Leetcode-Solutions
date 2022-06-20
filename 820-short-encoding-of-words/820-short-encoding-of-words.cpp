class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        sort(words.begin(),words.end(),[&words](string a, string b){
		    return a.size() < b.size();    
	    });
        for(int i=0; i < words.size(); i++){
            ans += words[i].size()+1;
        }
        for(int i=0; i < words.size(); i++){
            for(int j=i+1; j < words.size(); j++){
                if(words[j].substr(words[j].size() - words[i].size()) == words[i]){
                    ans -= words[i].size()+1;
                    break;
                }
            }
        }
        return ans;
    }
};