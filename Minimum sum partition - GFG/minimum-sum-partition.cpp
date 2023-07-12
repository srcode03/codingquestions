//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	    for(int i=0;i<n;i++)
	    {
	        dp[i][0]=1;
	    }
	    dp[0][arr[0]]=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            int notake=dp[i-1][j];
	            int take=0;
	            if(arr[i]<=j)
	            {
	                take=dp[i-1][j-arr[i]];
	            }
	            dp[i][j]=take||notake;
	        }
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<=sum;i++)
	    {
	        if(dp[n-1][i]==1)
	        {
	             mini=min(mini,abs((sum-i)-i));   
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends