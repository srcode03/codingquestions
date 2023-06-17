//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long 
class Solution {
  public:
    bool func(ll int mid,int H,vector<int>&piles,int N)
    {
        ll int c=0;
        for(int i=0;i<N;i++)
        {
            if(piles[i]<=mid)
            {
                c=c+1;
            }
            else{
                if(piles[i]%mid==0)
                {
                    c=c+piles[i]/mid;
                }
                else{
                    c=c+piles[i]/mid+1;
                }
            }
        }
        if(c<=H)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        ll int l=0;
        ll int h=1e18;
        ll int ans=-1;
        while(l<=h)
        {
            ll int mid=(l+h)/2;
            if(func(mid,H,piles,N))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends