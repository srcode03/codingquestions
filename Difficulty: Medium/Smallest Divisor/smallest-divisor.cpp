//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int func(int mid,vector<int>&nums,int K)
    {
        int ct=0;
        for(int i=0;i<nums.size();i++)
        {
            ct+=ceil(float(nums[i])/mid);
        }
        return ct<=K;
    }
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int ans=1;
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(func(mid,nums,K))
            {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends