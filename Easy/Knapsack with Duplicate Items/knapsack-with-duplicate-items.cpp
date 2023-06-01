//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int w,int val[],int wt[],vector<vector<int>>&dp)
    {
        if(w==0)
        {
            return 0;
        }
        if(i==0)
        {
            return val[0]*(w/wt[0]);
        }
        if(dp[i][w]!=-1)
        {
            return dp[i][w];
        }
        int notake=solve(i-1,w,val,wt,dp);
        int take=-1e9;
        if(wt[i]<=w)
        {
            take=val[i]+solve(i,w-wt[i],val,wt,dp);
        }
        return dp[i][w]=max(take,notake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        int ans=solve(N-1,W,val,wt,dp);
        if(ans==-1e9)
        {
            return 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends