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
	    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
	    for(int i=0;i<n;i++)
	    {
	        dp[i][0]=true;
	    }
	    dp[0][arr[0]]=true;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(j>=arr[i])
	            {
	                dp[i][j]=dp[i-1][j-arr[i]]|dp[i-1][j];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    vector<int>t;
	    for(int i=0;i<=sum;i++)
	    {
	        if(dp[n-1][i]==true)
	        {
	            t.push_back(i);
	        }
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<t.size();i++)
	    {
	        mini=min(mini,abs(sum-2*t[i]));
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