class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
      
        vector<vector<int>>mat(n) ;
        int edges = 0 ;
        vector<int>visited(n,0) ;
        vector<int>indeg(n,0) ;
        
        for(int i=0;i<n;i++)
        {
            if(left[i]!=-1)
            {
                mat[i].push_back(left[i]) ;
                edges++ ;
                indeg[left[i]]++ ;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if( right[i] != -1 )
            {
                mat[i].push_back(right[i]) ;
                edges++ ;
                indeg[right[i]]++ ;
            }
        }
        
        queue<int>pq;
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]>1)return false ;
            
            if(indeg[i]==0)
                pq.push(i) ;
        }
        
        int cnt = 0 ;
        
        while(!pq.empty())
        {
            auto temp = pq.front() ;
            pq.pop() ;
            
           // visited[temp] = 1 ;
            cnt++ ;
            
             for(auto i:mat[temp]){
	            indeg[i]--;
	            if(indeg[i] == 0)pq.push(i);} 
            
            
        }
        
        if( cnt != n || edges != n-1 )
            return false ;
        
        return true ;
    }
};