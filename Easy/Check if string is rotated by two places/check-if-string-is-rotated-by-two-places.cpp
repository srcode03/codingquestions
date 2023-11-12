//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length()!=str2.length())
        {
            return 0;
        }
        if(str1.length()==1)
        {
            return 1;
        }
        if(str1.length()==2)
        {
            return str1==str2;
        }
        
        int i=2;
        int j=0;
        int n=str2.length();
        int fg=0;
        while(j<n)
        {
            if(str1[i]!=str2[j])
            {
                fg=1;
                break;
            }
            j++;
            i=(i+1)%n;
        }
        if(fg==0)
        {
            return 1;
        }
        fg=0;
        i=n-2;
        j=0;
        while(j<n)
        {
            if(str1[i]!=str2[j])
            {
                fg=1;
                break;
            }
            j++;
            i=(i+1)%n;
        }
        if(fg==0)
        {
            return 1;
        }
        fg=0;
        i=0;
        j=n-2;
        while(j<n)
        {
            if(str1[i]!=str2[j])
            {
                fg=1;
                break;
            }
            j=(j+1)%n;
            i++;
        }
        if(fg==0)
        {
            return 1;
        }
        fg=0;
        i=0;
        j=2;
        while(j<n)
        {
            if(str1[i]!=str2[j])
            {
                fg=1;
                break;
            }
            i++;
            j=(j+1)%n;
        }
        if(fg==0)
        {
            return 1;
        }
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends