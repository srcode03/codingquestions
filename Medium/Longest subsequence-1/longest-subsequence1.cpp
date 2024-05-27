//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
          map<int,int>mp;
        mp[a[0]]=1;
        for(int i=1;i<n;i++)
        {
            int x=a[i];
            mp[x]=max(mp[x-1],mp[x+1])+1;
        }
        int maxi=INT_MIN;
        map<int,int>::iterator it=mp.begin();
        while(it!=mp.end())
        {
            maxi=max(maxi,it->second);
            it++;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends