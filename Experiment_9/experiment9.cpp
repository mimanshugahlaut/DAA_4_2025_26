class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j) 
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        int diff=INT_MAX;
        for(int j=sum/2;j>=0;j--){
            if(dp[n][j]){
                diff=sum-2*j;
                break;
            }
        }
        return diff;
    }
};
