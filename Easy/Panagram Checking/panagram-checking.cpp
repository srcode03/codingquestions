//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        string ans(26,'0');
        for(auto ch:s)
        {
            if(ch>='A' && ch<='Z')
            {
                ans[ch-'A']='1';
            }
            else if(ch>='a' && ch<='z')
            {
                ans[ch-'a']='1';
            }
        }
        int ct=0;
        for(int i=0;i<26;i++)
        {
            if(ans[i]=='1')
            {
                ct++;
            }
        }
        return ct==26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends