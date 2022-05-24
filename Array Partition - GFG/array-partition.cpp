// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[1000001];
    bool solve(int st,vector<int> &arr,int k,int m){
        int n = arr.size();
        if(st >= n) return true;
        if(dp[st] != -1) return dp[st];
        for(int i=st+k-1;i<n;i++){
            int sub = abs(arr[i] - arr[st]);
            if(sub > m) break;
            bool next = solve(i+1,arr,k,m);
            if(next) return dp[st] = true;
        }
        return dp[st] = false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &arr){
        // code here
          sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof dp);
        return solve(0,arr,K,M);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends