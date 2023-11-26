//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>ans;
    int val;
    void solve2(int N)
    {
        if(N>=val)
        {
            ans.push_back(N);
            return;
        }
        ans.push_back(N);
        solve2(N+5);
    }
    int solve(int N)
    {
        if(N<=0)
        {
            return N;
        }
        ans.push_back(N);
        solve(N-5);
    }
    vector<int> pattern(int N){
        // code here
        val=N;
        N=solve(N);
        solve2(N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends