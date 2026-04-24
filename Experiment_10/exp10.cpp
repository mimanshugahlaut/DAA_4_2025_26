class Solution {
public:
    long long solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        if (j == t.size()) return 1;   
        if (i == s.size()) return 0;     
      
        if (dp[i][j]!=-1) return dp[i][j];

        long long count=solve(i+1, j, s, t, dp);
        if (s[i]==t[j]){
            count+=solve(i+1, j+1, s, t, dp);
        }
        return dp[i][j]=count;
    }

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size(), vector<long long>(t.size(),-1));
        return solve(0,0,s,t,dp);
    }
};
/*
  Time Complexity: O(s*t), 
  Space Complexity: O(s*t) for the DP table,
*/
