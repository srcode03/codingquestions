//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
#define ll long long 
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    ll x=1,y=1,res=INT_MIN,maxi=1,mini=1;
	    ll t=1;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max({x*nums[i],y*nums[i],t*nums[i]});
            mini=min({x*nums[i],y*nums[i],t*nums[i]});
            res=max({maxi,mini,res});
            x=maxi;
            y=mini;
        }
        return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends