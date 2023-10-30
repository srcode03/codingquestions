//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector<ll>ct(33,0);
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=0;j<31;j++)
    	    {
    	        if(arr[i]&(1<<j))
    	        {
    	            ct[j]++;
    	        }
    	    }
    	}
    	ll ans=0;
    	for(int i=0;i<32;i++)
    	{
    	    ans+=(n-ct[i])*ct[i]*(1<<i);
    	}
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends