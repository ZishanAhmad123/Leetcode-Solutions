class Solution {
public:
     long operate(long val1, long val2, char op){
        if(op=='+') return val1+val2;
        else if(op=='-') return val1-val2;
        else if(op=='*') return val1*val2;
        else return val1/val2;
    }
    
    int calculate(string s) {
        // if(s[0]=='-') s = '0' + s;
        unordered_map<char, int> prec;
		// assigning precedence
        prec['+']=1;
        prec['-']=1;
        prec['*']=2;
        prec['/']=2;
        
        stack<long> nums;   // stack for storing num
        stack<char> opr;    // stack for storing operation
        
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                i++;
                continue;
            }
            
            if(isdigit(s[i])){
                long val=0;
                while(i<s.size() && isdigit(s[i])){
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                nums.push(val);
            }
            else{
                while(!opr.empty() && prec[s[i]] <= prec[opr.top()]){
                    long val2 = nums.top(); nums.pop();
                    long val1 = nums.top(); nums.pop();
                    char op = opr.top(); opr.pop();
                    long ans = operate(val1, val2, op);
                    nums.push(ans);
                }
                
                opr.push(s[i]);
                i++;
            }
        }
        
        // possibly some operator remain in stack 
        while(!opr.empty() && prec[s[i]] <= prec[opr.top()]){
            long val2 = nums.top(); nums.pop();
            long val1 = nums.top(); nums.pop();
            char op = opr.top(); opr.pop();
            long ans = operate(val1, val2, op);
            nums.push(ans);
        }
               
        int ans = nums.top();
        return ans;

    }
};