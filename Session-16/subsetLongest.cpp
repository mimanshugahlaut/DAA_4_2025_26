#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int i,int sum,vector<int>& arr,int target,vector<vector<int>>& dp){
    if(i==arr.size()){
        if(sum==target) return 0;
        else return -100000;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    int take=-100000;
    
    if(sum+arr[i]<=target)
        take=1+solve(i+1,sum+arr[i],arr,target,dp);
    
    int nottake=solve(i+1,sum,arr,target,dp);
    
    dp[i][sum]=max(take,nottake);
    return dp[i][sum];
}

vector<int> longest(vector<vector<int>>& dp,vector<int>& arr,int target){
    int i=0;
    int sum=0;
    vector<int> ans;
    
    while(i<arr.size()){
        int take=-100000;
        
        if(sum+arr[i]<=target)
            take=1+dp[i+1][sum+arr[i]];
            
        int nottake=dp[i+1][sum];
        
        if(take>=nottake){
            ans.push_back(arr[i]);
            sum+=arr[i];
        }
        i++;
    }
    return ans;
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
    
    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    
    int length=solve(0,0,arr,target,dp);
    
    if(length<0){
        cout<<"No subset exists\n";
        return 0;
    }
    
    cout<<"Length of longest subset: "<<length<<endl;
    
    vector<int> result=longest(dp,arr,target);
    
    cout<<"Longest subset: ";
    for(int x:result)
        cout<<x<<" ";
        
    return 0;
}
