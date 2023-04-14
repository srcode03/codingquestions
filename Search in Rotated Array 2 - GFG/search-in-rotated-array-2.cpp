//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) {
        // Code here
        int mini=-1;
        int l=0;
        int h=N-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(A[mid]==key || A[l]==key || A[h]==key)
            {
                return 1;
            }
            if(A[mid]==A[l] && A[mid]==A[h])
            {
                l++;
                h--;
            }
            else if(A[l]<=A[mid])
            {
                if(key<A[mid] && key>=A[l])
                {
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else if(A[h]>=A[mid])
            {
                if(key>=A[mid] && key<=A[h])
                {
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends