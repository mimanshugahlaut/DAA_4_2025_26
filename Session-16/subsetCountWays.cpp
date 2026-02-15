
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i,int sum,vector<int>& arr,int target,vector<vector<int>>& dp){
    if(i==arr.size()){
        if(sum==target) return 1;
        else return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    int take=0;
    
    if(sum+arr[i]<=target)
        take=solve(i+1,sum+arr[i],arr,target,dp);
    
    int nottake=solve(i+1,sum,arr,target,dp);
    
    return dp[i][sum]=take+nottake;
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    
    vector<int> arr(n);
    
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int target;
    cout<<"Enter target value: ";
    cin>>target;
    
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    
    cout<<"Number of subsets: ";
    cout<<solve(0,0,arr,target,dp);
    

    return 0;
}
