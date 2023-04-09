//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        // code here
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<N;i++)
        {
            if(st.empty())
            {
                st.push(arr[i]);
            }
            else{
                if(arr[i]>=0)
                {
                    st.push(arr[i]);
                }
                else{
                    int fg=0;
                    while(!st.empty())
                    {
                        if(st.top()<0)
                        {
                            break;
                        }
                        else if(st.top()<abs(arr[i]))
                        {
                            st.pop();
                        }
                        else if(st.top()==-arr[i])
                        {
                            st.pop();
                            fg=1;
                            break;
                        }
                        else{
                            fg=1;
                            break;
                        }
                    }
                    if(fg==0)
                    {
                        st.push(arr[i]);
                    }
                }
                
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends