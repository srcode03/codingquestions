//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n=s2.length();
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[0])
            {
                int fg=0;
                for(int j=0;j<n;j++)
                {
                    if(s1[(i+j)%n]!=s2[j])
                    {
                        fg=1;
                        break;
                    }
                }
                if(fg==0)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends