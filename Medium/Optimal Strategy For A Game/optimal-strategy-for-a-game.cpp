//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long
class Solution{
    public:
    ll solve(ll i,ll j,int arr[],vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=max(arr[i]+min(solve(i+2,j,arr,dp),solve(i+1,j-1,arr,dp)),arr[j]+min(solve(i+1,j-1,arr,dp),solve(i,j-2,arr,dp)));
    }
    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        ll i=0;
        ll j=n-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(i,j,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends