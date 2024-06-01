//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        map<char,int>mp;
        int x=0,y=0;
        string a;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==0)
            {
                a.push_back(s[i]);
            }
           mp[s[i]]+=1;
        }
        for(int i=0;i<a.length();i++)
        {
            if(mp[a[i]]%2==1 && a[i]%2==1)
            {
                x++;
            }
            else if(mp[a[i]]%2==0 && a[i]%2==0)
            {
                y++;
            }
        }
        return ((x+y)%2)==1?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends