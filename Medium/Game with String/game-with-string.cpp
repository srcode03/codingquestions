//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k)
    {
        // code here
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a']+=1;
        }
        sort(v.begin(),v.end(),greater<int>());
        while(k>0)
        {
            if(v[0])
            {
                v[0]-=1;
                sort(v.begin(),v.end(),greater<int>());
                k--;
            }
            else{
                break;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=(v[i]*v[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends