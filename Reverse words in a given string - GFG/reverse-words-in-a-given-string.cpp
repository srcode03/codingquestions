//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans="";
        string t="";
       for(int i=s.length()-1;i>=0;i--)
       {
           if(s[i]=='.')
           {
               reverse(t.begin(),t.end());
               ans.append(t);
               ans.push_back('.');
               t="";
           }
           else{
               t+=s[i];
           }
       }
       reverse(t.begin(),t.end());
       ans.append(t);
       return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends