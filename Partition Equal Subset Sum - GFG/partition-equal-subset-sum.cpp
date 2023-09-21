//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int i,int sum,int arr[],vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(i==0)
        {
            if(sum==arr[0])
            {
                return true;
            }
            return false;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        bool notake=solve(i-1,sum,arr,dp);
        bool take=false;
        if(sum>=arr[i])
        {
            take=solve(i-1,sum-arr[i],arr,dp);
        }
        return dp[i][sum]=take||notake;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2)return false;
        vector<vector<int>>dp(N,vector<int>(sum/2+1,-1));
        return solve(N-1,sum/2,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends