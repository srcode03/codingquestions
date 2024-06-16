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
    vector<int> getPrimes(int n) {
        // code here
        vector<int>isprime(n+1,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(isprime[i]==1)
            {
                for(int j=2*i;j<=n;j+=i)
                {
                    isprime[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(isprime[i]==1 && isprime[n-i]==1)
            {
                return {i,n-i};
            }
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends