class Solution {
public:
    int countSegments(string s) {
         int count = 0, n=s.length();
    
    if(n==0)
        return 0;
    
    if(n==1 && s[0]==' ')
        return 0;
    
    for(int i=1; i<n; i++)
    {
        if(s[i]==' '&&s[i-1]!=' ')
            count++;
    }
    
    if(s[n-1]==' ')
        return count;
    
    else
        return count+1;
    }
};