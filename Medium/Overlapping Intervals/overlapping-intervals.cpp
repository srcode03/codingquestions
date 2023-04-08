//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         int s=intervals[0][0];
         int e=intervals[0][1];
         vector<int>t;
         t.push_back(s);
         t.push_back(e);
         ans.push_back(t);
         t.clear();
         for(int i=1;i<intervals.size();i++)
         {
            if(intervals[i][0]>s && intervals[i][0]>e)
            {
                t.push_back(intervals[i][0]);
                t.push_back(intervals[i][1]);
                ans.push_back(t);
                t.clear();
                s=intervals[i][0];
                e=intervals[i][1];
            }
            else if(intervals[i][1]>e)
            {
                ans.pop_back();
                if(intervals[i][0]<s)
                {
                    t.push_back(intervals[i][0]);
                     s=intervals[i][0];
                }
                else{
                    t.push_back(s);
                }
                t.push_back(intervals[i][1]);
                ans.push_back(t);
                t.clear();
                e=intervals[i][1];
            }
            else if(intervals[i][0]<s)
            {
                ans.pop_back();
                t.push_back(intervals[i][0]);
                if(intervals[i][1]>e)
                {
                    t.push_back(intervals[i][1]);
                    e=intervals[i][1];
                }
                else{
                    t.push_back(e);
                }
                ans.push_back(t);
                t.clear();
                s=intervals[i][0];
            }
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends