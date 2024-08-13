//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
#define ll long long
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        ll l=1;
        ll h=n;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            if(mid*mid==n)
            {
                return mid;
            }
            if(mid*mid<n)
            {
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return l-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends