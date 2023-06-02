//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i,int b,int k,int n,int A[],vector<vector<vector<int>>>&dp)
    {
        if(i==n || k==0)
        {
            return 0;
        }
        if(dp[i][b][k]!=-1)
        {
            return dp[i][b][k];
        }
        if(b==1)
        {
            return dp[i][b][k]=max(-A[i]+solve(i+1,0,k,n,A,dp),solve(i+1,1,k,n,A,dp));
        }
        else{
            return dp[i][b][k]=max(A[i]+solve(i+1,1,k-1,n,A,dp),solve(i+1,0,k,n,A,dp));
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        int ans=INT_MIN;
        for(int i=1;i<=K;i++)
        {
            ans=max(ans,solve(0,1,i,N,A,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends