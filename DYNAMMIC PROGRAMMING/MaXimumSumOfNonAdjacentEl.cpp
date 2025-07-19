// Problem Statement:

// Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

// Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.


#include<bits/stdc++.h>
using namespace std;
// Recursion
int maxSum(vector<int>&arr,int idx){
    if(idx>=arr.size()){
        return 0;
    }
    
    return max(arr[idx]+maxSum(arr,idx+2),maxSum(arr,idx+1));
}
// Memoization
int maxSumMemo(vector<int>&arr,int idx,vector<int>&dp){
    if(idx>=arr.size()){
        return 0;
    }
    if(dp[idx]!=-1)return dp[idx];

    return dp[idx]=max(arr[idx]+maxSum(arr,idx+2),maxSum(arr,idx+1));
}
// Tabulation
int maxSumTab(vector<int>&arr){
    int n=arr.size();

    vector<int>dp(n+1,-1);
    dp[n]=0;
    dp[n+1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
    }
    return dp[0];

}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n+1,-1);
    cout<<maxSumTab(arr);
    return 0;
}