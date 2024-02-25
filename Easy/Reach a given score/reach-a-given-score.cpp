//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<ll>dp(n+1,0);
    	dp[0]=1;
    	for(ll i=3;i<=n;i++)
    	{
    	    dp[i]=dp[i]+dp[i-3];
    	}
    	for(ll i=5;i<=n;i++)
    	{
    	    dp[i]=dp[i]+dp[i-5];
    	}
        for(ll i=10;i<=n;i++)
    	{
    	    dp[i]=dp[i]+dp[i-10];
    	}	
    	return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends