//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string>ans;
    void solve(int i,string ds,string s)
    {
        if(i==s.length()-1)
        {
            ds.push_back(s[i]);
            ans.push_back(ds);
            return;
        }
        ds.push_back(s[i]);
        ds.push_back(' ');
        solve(i+1,ds,s);
        ds.pop_back();
        solve(i+1,ds,s);
    }
    vector<string> permutation(string S){
        // Code Here
        string ds;
        solve(0,ds,S);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends