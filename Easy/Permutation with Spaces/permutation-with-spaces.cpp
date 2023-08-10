//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string>ans;
    void solve(string in,string op)
    {
        if(in.length()==0)
        {
            ans.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        op2.push_back(' ');
        op2.push_back(in[0]);
        op1.push_back(in[0]);
        in.erase(0,1);
        solve(in,op1);
        solve(in,op2);
    }
    
    vector<string> permutation(string S){
        // Code Here
        string op;
        op+=S[0];
        string in=S.substr(1);
        solve(in,op);
        sort(ans.begin(),ans.end());
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