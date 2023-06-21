//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        map<char,int>mp;
        for(int i=0;i<N;i++)
        {
            mp[tasks[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int f=pq.top().first;
        int idle=(K)*(pq.top().first-1);
        pq.pop();
        while(!pq.empty())
        {
            idle=idle-min(f-1,pq.top().first);
            pq.pop();
        }
        return tasks.size()+max(0,idle);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends