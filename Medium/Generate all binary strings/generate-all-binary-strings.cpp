//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(int i,int n,string s1,vector<string>&ans)
    {
        if(s1.length()==n)
        {
            ans.push_back(s1);
            return;
        }
        if(i==n-1)
        {
            if(s1.length()==n-1)
            {
                if(s1[i-1]=='1')
                {
                    s1.push_back('0');
                    ans.push_back(s1);
                }
                else{
                    s1.push_back('0');
                    ans.push_back(s1);
                    s1.pop_back();
                    s1.push_back('1');
                    ans.push_back(s1);
                }
            }
            return;
        }
        
        if(s1[i-1]=='1')
        {
            s1.push_back('0');
            solve(i+1,n,s1,ans);
            s1.pop_back();
            solve(i+1,n,s1,ans);
            
        }
        else{
            s1.push_back('0');
            solve(i+1,n,s1,ans);
            s1.pop_back();
            s1.push_back('1');
            solve(i+1,n,s1,ans);
        }
    }
    void generateBinaryStrings(int num){
        //Write your code
        string s1="0";
        string s2="1";
        vector<string>ans;
        solve(1,num,s1,ans);
        solve(1,num,s2,ans);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends