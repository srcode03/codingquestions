//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int i,vector<int>arr,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return 1;
        }
        if(i==0)
        {
            if(sum-arr[0]==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        int notake=solve(i-1,arr,sum,dp);
        int take=0;
        if(arr[i]<=sum)
        {
         take=solve(i-1,arr,sum-arr[i],dp);
        }
        return dp[i][sum]=take||notake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=solve(n-1,arr,sum,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends