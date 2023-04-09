//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int>ans(n);
        stack<int>st;
        st.push(a[0]);
        ans[0]=-1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>st.top())
            {
                ans[i]=st.top();
                st.push(a[i]);
            }
            else{
                int fg=0;
                while(!st.empty())
                {
                    if(st.top()<a[i])
                    {
                        ans[i]=st.top();
                        fg=1;
                        st.push(a[i]);
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(fg==0)
                {
                    ans[i]=-1;
                    st.push(a[i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends