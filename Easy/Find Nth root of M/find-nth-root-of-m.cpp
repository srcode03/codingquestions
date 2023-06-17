//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define ll long long 
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    ll int l=1;
	    ll int h=m;
	    while(l<=h)
	    {
	        ll int mid=(l+h)/2;
	        ll int t=1;
	        for(int i=0;i<n;i++)
	        {
	            if(t<=1e9)
	            {
	                t=t*mid;
	            }
	            else{
	                h=mid-1;
	                continue;
	            }
	        }
	        if(t==m)
	        {
	            return mid;
	        }
	        if(t<m)
	        {
	            l=mid+1;
	        }
	        else if(t>m)
	        {
	            h=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends