//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        vector<int>ans;
        ans.push_back(-1);
        stack<int>st;
        st.push(arr[0]);
        for(int i=1;i<n;i++)
        {
            int fg=0;
            while(!st.empty())
            {
                if(st.top()<arr[i])
                {
                    fg=1;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(fg==1)
            {
                ans.push_back(st.top());
            }
            else{
                ans.push_back(-1);
            }
            st.push(arr[i]);
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