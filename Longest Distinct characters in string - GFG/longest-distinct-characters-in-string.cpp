//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.length();
    int i=0;
    int j=0;
    map<char,int>mp;
    int ans=-1;
    while(j<n)
    {
        if(mp[s[j]]==1)
        {
            ans=max(ans,j-i);
            while(mp[s[j]]==1)
            {
                mp[s[i]]=0;
                i++;
            }
            mp[s[j]]=1;
        }
        else{
            mp[s[j]]=1;
        }
        j++;
    }
    ans=max(ans,j-i);
    return ans;
}