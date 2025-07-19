// Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.


#include<bits/stdc++.h>
using namespace std;
// Recursion only
int climb(int n){
    if(n==0||n==1){
        return 1;
    }
    return climb(n-1)+climb(n-2);
}

// recursion + memoization

int climbS(int n,vector<int>&dp){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1)return dp[n];
    return dp[n]=climbS(n-1,dp)+climbS(n-2,dp);
}
// tabulation
int tabulation(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for (int i = 2; i <= n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    // cout<<climbS(n,dp);
    cout<<tabulation(n);
    return 0;
}