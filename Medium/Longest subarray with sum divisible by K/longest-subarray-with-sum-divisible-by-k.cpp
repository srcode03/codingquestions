//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int>pre(n);
	    pre[0]=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        pre[i]=pre[i-1]+arr[i];
	    }
	    unordered_map<int,int>mp;
	    mp[0]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        int r=pre[i]%k;
	        if(r<0)
	        {
	            r+=k;
	        }
	        if(mp.find(r)==mp.end())
	        {
	            mp[r]=i;
	        }
	        else{
	            ans=max(ans,i-mp[r]);
	        }
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends